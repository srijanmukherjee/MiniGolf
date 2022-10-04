#ifndef GOLFGAME_GAME_H
#define GOLFGAME_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <spdlog/spdlog.h>
#include <vector>

#include "TextureManager.h"
#include "Scene.h"

struct SceneLoadAnimationMeta {
    int r;
    int g;
    int b;
    int a;
};

class Game {
public:
    virtual ~Game();
    virtual void Init(const char *title, int x, int y, int width, int height, bool fullscreen);

    virtual void HandleEvents();
    virtual void Update();
    void Render();
    void Clean();

    void SetWindowTitle(const char * title);

    [[nodiscard]] bool IsRunning() const { return m_Running; }

    static SDL_Renderer* renderer;

    template <class T>
    static void Start(int targetFPS, const char *title, int x, int y, int width, int height, bool fullscreen) {
        const int frameDelay = 1000 / targetFPS;

        Uint32 frameStart;
        Uint32 frameTime;

        Game* game = new T();

        game->Init(title, x, y, width, height, fullscreen);

        while (game->IsRunning()) {
            frameStart = SDL_GetTicks();

            game->HandleEvents();
            game->Update();
            game->Render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameDelay > frameTime) {
                SDL_Delay(frameDelay - frameTime);
            }

            // display fps (TODO: display only for debug build using macro)
            frameTime = SDL_GetTicks() - frameStart;
            std::string titleWithFPS = title;
            titleWithFPS += " | FPS: " + std::to_string(static_cast<int>(1000.0/frameTime));
            game->SetWindowTitle(titleWithFPS.c_str());
        }

        delete game;
    }

private:
    bool m_Running = false;
    bool m_AnimatingSceneLoad = false;
    SceneLoadAnimationMeta m_AnimationMeta{0, 0, 0, 255};

    void PresentScene();

protected:
    SDL_Window *window = nullptr;
    Scene *currentScene = nullptr;

    virtual void RenderGame() { };
    virtual void ProcessEvent(SDL_Event& event) { };

    void LoadScene(Scene *scene);
};


#endif //GOLFGAME_GAME_H
