#ifndef GOLFGAME_LEVELCOMPLETESCENE_H
#define GOLFGAME_LEVELCOMPLETESCENE_H


#include "../../engine/Scene.h"

class LevelCompleteScene : public Scene {
public:
    void Init() override;
    void Draw() override;
    void Update(float deltaTime) override;
    void HandleEvent(SDL_Event &event) override;

    ~LevelCompleteScene();
};


#endif //GOLFGAME_LEVELCOMPLETESCENE_H
