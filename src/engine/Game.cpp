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
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

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
                if (currentScene) currentScene->HandleEvent(event);
                break;
        }
}

void Game::Render() {
    static SDL_Rect rect{0, 0, 800, 640};

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (currentScene) currentScene->Draw();

    if (m_AnimatingSceneLoad) {
        SDL_SetRenderDrawColor(renderer, m_AnimationMeta.r, m_AnimationMeta.g,
                                        m_AnimationMeta.b, m_AnimationMeta.a);
        SDL_RenderFillRect(renderer, &rect);
        m_AnimationMeta.a -= 5;

        if (m_AnimationMeta.a <= 0) {
            m_AnimationMeta.a = 255;
            m_AnimatingSceneLoad = false;
        }
    }
    SDL_RenderPresent(renderer);
}

void Game::Update() {
    if (currentScene)
        currentScene->Update();
}

void Game::Clean() {
    delete currentScene;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    spdlog::info("Game cleaned");
}

void Game::PresentScene() {
    if (currentScene == nullptr) return;
    m_AnimatingSceneLoad = true;
}

void Game::LoadScene(Scene *scene) {
    spdlog::info("loading scene");
    delete currentScene;
    currentScene = scene;
    currentScene->Init();
    PresentScene();
}

Game::Game() {
    m_AnimationMeta.r = 0;
    m_AnimationMeta.g = 0;
    m_AnimationMeta.b = 0;
    m_AnimationMeta.a = 255;
}
