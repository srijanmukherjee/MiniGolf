#include "GolfGame.h"
#include "scenes/play/PlayScene.h"
#include "scenes/menu/MenuScene.h"

void GolfGame::Init(const char *title, int x, int y, int width, int height, bool fullscreen) {
    Game::Init(title, x, y, width, height, fullscreen);

    LoadScene(new MenuScene());
};

GolfGame::~GolfGame() = default;
