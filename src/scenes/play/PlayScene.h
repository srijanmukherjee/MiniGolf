#ifndef GOLFGAME_PLAYSCENE_H
#define GOLFGAME_PLAYSCENE_H


#include "../../engine/Scene.h"
#include "../../res/Levels.h"
#include "../../entity/Clock/ClockEntity.h"

#include <chrono>

class PlayScene : public Scene {
public:
    void Init() override;
    void Update(float deltaTime) override;
    void HandleEvent(SDL_Event &event) override;

    void LoadLevel(const LevelDescriptor& levelDescriptor);

private:
    int m_CurrentLevel = 0;
    long m_TimeTookMillis = 0;

    ClockEntity *m_ClockEntity = nullptr;
};


#endif //GOLFGAME_PLAYSCENE_H
