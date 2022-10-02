#include <SDL2/SDL.h>
#include <iostream>
#include "engine/Game.h"
#include "GolfGame.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640

Game *game = nullptr;

int main(int arc, char **argv) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    Uint32 frameTime;

    game = new GolfGame();

    game->Init("Golf Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while (game->IsRunning()) {
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    delete game;

    return 0;
}