#include "PlayScene.h"
#include "../../entitiy/Ball/BallEntity.h"
#include "../../GolfTileMap.h"

BallEntity *ballEntity;
GolfTileMap *tileMap;

void PlayScene::Init() {
    Scene::Init();
    ballEntity = dynamic_cast<BallEntity *>(&m_Manager.AddEntity<BallEntity>());
    tileMap = new GolfTileMap();
}

void PlayScene::Draw() {
    tileMap->Render();
    Scene::Draw();
}

void PlayScene::Update() {
    tileMap->Update();
    Scene::Update();
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
