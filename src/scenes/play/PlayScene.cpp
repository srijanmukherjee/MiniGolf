#include "PlayScene.h"
#include "../../GolfTileMap.h"
#include "../../res/Constant.h"

#include "../../entity/Ball/BallEntity.h"
#include "../../entity/Wall/WallEntity.h"
#include "../../entity/Obstacle/ObstacleSmall.h"
#include "../../entity/Obstacle/ObstacleBig.h"
#include "../../entity/Goal/GoalEntity.h"

BallEntity *ballEntity;
GolfTileMap *tileMap;

void PlayScene::Init() {
    Scene::Init();
    LoadLevel(levels[0]);
    tileMap = new GolfTileMap();
    m_Manager.Update(0);
    m_CollisionManager.StartDetectingCollision();
}

void PlayScene::Draw() {
    tileMap->Render();
    Scene::Draw();
}

void PlayScene::Update(float deltaTime) {
    tileMap->Update(deltaTime);
    Scene::Update(deltaTime);
}

void PlayScene::HandleEvent(SDL_Event &event) {
    Scene::HandleEvent(event);
    switch(event.type) {
        case SDL_MOUSEBUTTONDOWN:
            ballEntity->OnMouseDown();
            break;
        case SDL_MOUSEBUTTONUP:
            ballEntity->OnMouseUp();
            DisplayGridCoords();
            break;
        case SDL_MOUSEMOTION:
            ballEntity->OnMouseMove();
        default:
            break;
    }

}

void PlayScene::LoadLevel(const LevelDescriptor& levelDescriptor) {
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
    delete ballEntity;
    ballEntity = &m_Manager.AddEntity<BallEntity>(this);
    int w = ballEntity->GetComponent<TransformComponent>().width;
    ballEntity->GetComponent<TransformComponent>().position = Vector2D(
            levelDescriptor.ballPos.first * 32 + w / 2,levelDescriptor.ballPos.second * 32 + w / 2);
}

void PlayScene::DisplayGridCoords() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    spdlog::info("mouse [{}, {}]", static_cast<int>(x / 32), static_cast<int>(y / 32));
}
