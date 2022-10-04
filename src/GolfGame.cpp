#include "GolfGame.h"
#include "scenes/play/PlayScene.h"

void GolfGame::Init(const char *title, int x, int y, int width, int height, bool fullscreen) {
    Game::Init(title, x, y, width, height, fullscreen);

    LoadScene(new PlayScene());
};

GolfGame::~GolfGame() = default;
