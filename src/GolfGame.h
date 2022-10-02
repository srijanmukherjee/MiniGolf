#ifndef GOLFGAME_GOLFGAME_H
#define GOLFGAME_GOLFGAME_H


#include "engine/Game.h"

class GolfGame : public Game {
public:
    GolfGame() = default;
    ~GolfGame() override;

    void Init(const char *title, int x, int y, int width, int height, bool fullscreen) override;
    void Update() override;
    void HandleEvents() override;
    void RenderGame() override;
};


#endif //GOLFGAME_GOLFGAME_H
