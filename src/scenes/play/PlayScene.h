#ifndef GOLFGAME_PLAYSCENE_H
#define GOLFGAME_PLAYSCENE_H


#include "../../engine/Scene.h"

class PlayScene : public Scene {
public:
    void Init() override;
    void Draw() override;
    void Update() override;
    void HandleEvent(SDL_Event &event) override;
};


#endif //GOLFGAME_PLAYSCENE_H
