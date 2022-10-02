#ifndef GOLFGAME_GOLFGAME_H
#define GOLFGAME_GOLFGAME_H


#include "engine/Game.h"
#include "engine/GameObject.h"

class GolfGame : public Game {
public:
    GolfGame() = default;
    ~GolfGame() override;

    void Init(const char *title, int x, int y, int width, int height, bool fullscreen) override;
    void Update() override;
private:

    void AddGameObject(GameObject *gameObject);
    std::vector<GameObject*> m_GameObjects;

protected:

    void RenderGame() override;
    void ProcessEvent(SDL_Event &event) override;
};


#endif //GOLFGAME_GOLFGAME_H
