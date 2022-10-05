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
    m_Manager.AddEntity<ObstacleSmall>(this).SetPosition(32, 64);
    m_Manager.AddEntity<ObstacleSmall>(this).SetPosition(64, 64);
    m_Manager.AddEntity<ObstacleSmall>(this).SetPosition(96, 64);
    m_Manager.AddEntity<ObstacleBig>(this).SetPosition(96, 196);
    m_Manager.AddEntity<ObstacleBig>(this).SetPosition(96, 196);
    m_Manager.AddEntity<ObstacleBig>(this).SetPosition(160, 196);
    m_Manager.AddEntity<ObstacleBig>(this).SetPosition(224, 196);
    m_Manager.AddEntity<WallEntity>(this, "wall_horizontal", SDL_Rect{ 0, -1, Constant::SCREEN_WIDTH, 1 });
    m_Manager.AddEntity<WallEntity>(this, "wall_horizontal", SDL_Rect{ 0, Constant::SCREEN_HEIGHT, Constant::SCREEN_WIDTH, 1 });
    m_Manager.AddEntity<WallEntity>(this, "wall_vertical", SDL_Rect{ -1, 0, 1, Constant::SCREEN_HEIGHT });
    m_Manager.AddEntity<WallEntity>(this, "wall_vertical", SDL_Rect{ Constant::SCREEN_WIDTH, 0, 1, Constant::SCREEN_HEIGHT });
    &m_Manager.AddEntity<GoalEntity>(this, 10, 10);
    ballEntity = &m_Manager.AddEntity<BallEntity>(this);
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
            break;
        case SDL_MOUSEMOTION:
            ballEntity->OnMouseMove();
        default:
            break;
    }
}
