#include "Game.h"

SDL_Renderer *Game::renderer = nullptr;

Game::~Game() {
    Clean();
}

void Game::Init(const char *title, int x, int y, int width, int height, bool fullscreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        spdlog::error("Subsystem initialisation failed");
        return;
    }

    Uint32 flags = 0;
    if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN;

    window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (window == nullptr) {
        spdlog::error("Failed to create window");
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        spdlog::error("Failed to create renderer");
        return;
    }

    m_Running = true;
    spdlog::info("Game initialised");

    // supposed to make things look good
//    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event))
        switch (event.type) {
            case SDL_QUIT:
                m_Running = false;
                break;
            default:
                ProcessEvent(event);
                break;
        }
}

void Game::Render() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    RenderGame();
    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    spdlog::info("Game cleaned");
}
