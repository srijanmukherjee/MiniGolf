#include "LevelCompleteScene.h"
#include "../../engine/Game.h"
#include "../menu/MenuScene.h"
#include "../../GolfTileMap.h"

void LevelCompleteScene::Init() {
    Scene::Init();
}

void LevelCompleteScene::Draw() {
    Scene::Draw();
}

void LevelCompleteScene::Update(float deltaTime) {
    Scene::Update(deltaTime);
}

void LevelCompleteScene::HandleEvent(SDL_Event &event) {
    Scene::HandleEvent(event);

    switch (event.type) {
        case SDL_MOUSEBUTTONUP:
            Game::GetInstance().LoadScene(new MenuScene());
    }
}

LevelCompleteScene::~LevelCompleteScene() {

}
