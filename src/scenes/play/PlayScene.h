#ifndef GOLFGAME_PLAYSCENE_H
#define GOLFGAME_PLAYSCENE_H


#include "../../engine/Scene.h"
#include "../../res/Levels.h"

class PlayScene : public Scene {
public:
    void Init() override;
    void Draw() override;
    void Update(float deltaTime) override;
    void HandleEvent(SDL_Event &event) override;

    void LoadLevel(const LevelDescriptor& levelDescriptor);
};


#endif //GOLFGAME_PLAYSCENE_H
