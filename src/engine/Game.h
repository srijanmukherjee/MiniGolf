#ifndef GOLFGAME_GAME_H
#define GOLFGAME_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <spdlog/spdlog.h>
#include <vector>

#include "TextureManager.h"

class Game {
public:
    Game() = default;
    virtual ~Game();
    virtual void Init(const char *title, int x, int y, int width, int height, bool fullscreen);

    virtual void HandleEvents();
    virtual void Update() = 0;
    void Render();
    void Clean();

    [[nodiscard]] bool IsRunning() const { return m_Running; }

    static SDL_Renderer* renderer;
private:
    bool m_Running = false;

protected:
    SDL_Window *window = nullptr;

    virtual void RenderGame() = 0;
    virtual void ProcessEvent(SDL_Event& event) = 0;
};


#endif //GOLFGAME_GAME_H
