#include <SDL2/SDL.h>

#include "engine/Game.h"
#include "GolfGame.h"
#include "res/Constant.h"

int main(int arc, char **argv) {
    Game::Start<GolfGame>(Constant::FPS, Constant::TITLE,
                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                          Constant::SCREEN_WIDTH, Constant::SCREEN_HEIGHT, false);
    return 0;
}