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
    virtual void Update(float deltaTime);
    void Render();
    void Clean();

    void SetWindowTitle(const char * title);

    [[nodiscard]] bool IsRunning() const { return m_Running; }

    static SDL_Renderer* renderer;

    template <class T>
    static void Start(int targetFPS, const char *title, int x, int y, int width, int height, bool fullscreen) {
        const int frameDelay = std::ceil(1000 / (float) targetFPS);

        Game* game = new T();

        game->Init(title, x, y, width, height, fullscreen);

        Uint32 lastFrameTime = 0;
        Uint32 time = 0;
        float delta = 0;

        while (game->IsRunning()) {
            time = SDL_GetTicks();
            delta = time - lastFrameTime;
            lastFrameTime = time;

            game->HandleEvents();
            game->Update(delta / 1000.0f);
            game->Render();

            if (delta < frameDelay) {
                SDL_Delay(frameDelay - delta);
            }
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
