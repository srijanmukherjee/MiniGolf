#include "PlayScene.h"
#include "../../entitiy/Ball/BallEntity.h"
#include "../../GolfTileMap.h"
#include "../../entitiy/Wall/WallEntity.h"
#include "../../res/Constant.h"
#include "../../entitiy/Obstacle/ObstacleSmall.h"
#include "../../entitiy/Obstacle/ObstacleBig.h"

BallEntity *ballEntity;
GolfTileMap *tileMap;

void PlayScene::Init() {
    Scene::Init();
    m_Manager.AddEntity<ObstacleSmall>(this).SetPosition(32, 64);
    m_Manager.AddEntity<ObstacleSmall>(this).SetPosition(64, 64);
    m_Manager.AddEntity<ObstacleSmall>(this).SetPosition(96, 64);
    m_Manager.AddEntity<ObstacleBig>(this).SetPosition(96, 196);
    m_Manager.AddEntity<WallEntity>(this, "wall_horizontal", SDL_Rect{ 0, -1, Constant::SCREEN_WIDTH, 1 });
    m_Manager.AddEntity<WallEntity>(this, "wall_horizontal", SDL_Rect{ 0, Constant::SCREEN_HEIGHT, Constant::SCREEN_WIDTH, 1 });
    m_Manager.AddEntity<WallEntity>(this, "wall_vertical", SDL_Rect{ -1, 0, 1, Constant::SCREEN_HEIGHT });
    m_Manager.AddEntity<WallEntity>(this, "wall_vertical", SDL_Rect{ Constant::SCREEN_WIDTH, 0, 1, Constant::SCREEN_HEIGHT });
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
