#ifndef GOLFGAME_MENUSCENE_H
#define GOLFGAME_MENUSCENE_H


#include "../../engine/Scene.h"

class MenuScene : public Scene {
public:
    ~MenuScene();
    void Init() override;
    void Draw() override;
    void Update(float deltaTime) override;
    void HandleEvent(SDL_Event &event) override;
};


#endif //GOLFGAME_MENUSCENE_H
