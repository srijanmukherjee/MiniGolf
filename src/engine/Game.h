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
    Game();
    virtual ~Game();
    virtual void Init(const char *title, int x, int y, int width, int height, bool fullscreen);

    virtual void HandleEvents();
    virtual void Update();
    void Render();
    void Clean();

    [[nodiscard]] bool IsRunning() const { return m_Running; }

    static SDL_Renderer* renderer;

private:
    bool m_Running = false;
    bool m_AnimatingSceneLoad = false;
    SceneLoadAnimationMeta m_AnimationMeta;

    void PresentScene();

protected:
    SDL_Window *window = nullptr;
    Scene *currentScene = nullptr;

    virtual void RenderGame() { };
    virtual void ProcessEvent(SDL_Event& event) { };

    void LoadScene(Scene *scene);
};


#endif //GOLFGAME_GAME_H
