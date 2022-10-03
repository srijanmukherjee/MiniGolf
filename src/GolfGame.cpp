#include "GolfGame.h"
#include "GolfTileMap.h"
#include "components/SpriteComponent.h"
#include "entitiy/Ball/BallEntity.h"

Manager manager;
BallEntity *ballEntity;


void GolfGame::Init(const char *title, int x, int y, int width, int height, bool fullscreen) {
    Game::Init(title, x, y, width, height, fullscreen);

    AddGameObject(new GolfTileMap());
    ballEntity = dynamic_cast<BallEntity *>(&manager.AddEntity<BallEntity>());
};

void GolfGame::Update() {
    for (auto & gameObject : m_GameObjects) {
        gameObject->Update();
    }

    manager.Update();
}

void GolfGame::ProcessEvent(SDL_Event &event) {
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

void GolfGame::RenderGame() {
    for (auto & gameObject : m_GameObjects) {
        gameObject->Render();
    }

    manager.Draw();
}

GolfGame::~GolfGame() {
}

void GolfGame::AddGameObject(GameObject *gameObject) {
    m_GameObjects.push_back(gameObject);
}
