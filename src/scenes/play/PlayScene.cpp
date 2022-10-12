#include "PlayScene.h"
#include "../../GolfTileMap.h"

#include "../../entity/Ball/BallEntity.h"
#include "../../entity/Wall/WallEntity.h"
#include "../../entity/Obstacle/ObstacleSmall.h"
#include "../../entity/Obstacle/ObstacleBig.h"
#include "../../entity/Goal/GoalEntity.h"
#include "../level_complete/LevelCompleteScene.h"

BallEntity *ballEntity;

const int TOTAL_LEVELS = sizeof(levels) / sizeof(LevelDescriptor);

void PlayScene::Init() {
    Scene::Init();
    LoadLevel(levels[m_CurrentLevel]);
}

void PlayScene::Update(float deltaTime) {
    Scene::Update(deltaTime);

    if (ballEntity->IsInsideGoal()) {
        if (m_CurrentLevel + 1 < TOTAL_LEVELS)
            LoadLevel(levels[++m_CurrentLevel]);
//        else
        Game::GetInstance().LoadScene(new LevelCompleteScene());
    }
}

void PlayScene::HandleEvent(SDL_Event &event) {
    Scene::HandleEvent(event);
    switch(event.type) {
        case SDL_MOUSEBUTTONDOWN:
            ballEntity->OnMouseDown();
            break;
        case SDL_MOUSEBUTTONUP:
            ballEntity->OnMouseUp();
            break;
        case SDL_MOUSEMOTION:
            ballEntity->OnMouseMove();
        default:
            break;
    }

}

void PlayScene::LoadLevel(const LevelDescriptor& levelDescriptor) {
    m_CollisionManager.StopDetectingCollision();
    m_Manager.Reset();
    m_CollisionManager.Reset();
    m_Manager.Refresh();
    m_Manager.AddEntity<GolfTileMap>(this);
    m_Manager.AddEntity<WallEntity>(this, "wall_horizontal", SDL_Rect{ 0, -1, Constant::SCREEN_WIDTH, 1 });
    m_Manager.AddEntity<WallEntity>(this, "wall_horizontal", SDL_Rect{ 0, Constant::SCREEN_HEIGHT, Constant::SCREEN_WIDTH, 1 });
    m_Manager.AddEntity<WallEntity>(this, "wall_vertical", SDL_Rect{ -1, 0, 1, Constant::SCREEN_HEIGHT });
    m_Manager.AddEntity<WallEntity>(this, "wall_vertical", SDL_Rect{ Constant::SCREEN_WIDTH, 0, 1, Constant::SCREEN_HEIGHT });

    for (auto & pos : levelDescriptor.smObstacles) {
        m_Manager.AddEntity<ObstacleSmall>(this).SetPosition(pos.first * 32, pos.second * 32);
    }

    for (auto & pos : levelDescriptor.lgObstacles) {
        m_Manager.AddEntity<ObstacleBig>(this).SetPosition(pos.first * 32, pos.second * 32);
    }

    m_Manager.AddEntity<GoalEntity>(this, levelDescriptor.goalPos.second, levelDescriptor.goalPos.first);
    ballEntity = &m_Manager.AddEntity<BallEntity>(this);
    int w = ballEntity->GetComponent<TransformComponent>().width;
    ballEntity->GetComponent<TransformComponent>().position = Vector2D(
            levelDescriptor.ballPos.first * 32 + w / 2,levelDescriptor.ballPos.second * 32 + w / 2);

    m_Manager.Update(0);
    m_CollisionManager.StartDetectingCollision();
}