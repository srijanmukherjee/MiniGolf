#include "GolfGame.h"
#include "GolfTileMap.h"
#include "GolfBallGameObject.h"

GolfBallGameObject* golfBall;

void GolfGame::Init(const char *title, int x, int y, int width, int height, bool fullscreen) {
    Game::Init(title, x, y, width, height, fullscreen);

    golfBall = new GolfBallGameObject("../assets/textures/golf-ball.png");

    AddGameObject(new GolfTileMap());
    AddGameObject(golfBall);
};

void GolfGame::Update() {
    for (auto & gameObject : m_GameObjects) {
        gameObject->Update();
    }
}

void GolfGame::ProcessEvent(SDL_Event &event) {
    switch(event.type) {
        case SDL_MOUSEBUTTONDOWN:
            golfBall->Hold();
            break;
        case SDL_MOUSEBUTTONUP:
            golfBall->Release();
            break;
        default:
            break;
    }
}

void GolfGame::RenderGame() {
    for (auto & gameObject : m_GameObjects) {
        gameObject->Render();
    }
}

GolfGame::~GolfGame() {
}

void GolfGame::AddGameObject(GameObject *gameObject) {
    m_GameObjects.push_back(gameObject);
}
