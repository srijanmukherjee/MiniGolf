#ifndef GOLFGAME_LEVELCOMPLETESCENE_H
#define GOLFGAME_LEVELCOMPLETESCENE_H


#include "../../engine/Scene.h"

class LevelCompleteScene : public Scene {
public:
    explicit LevelCompleteScene(long timeTook) : m_TimeTookMillis(timeTook) { };
    void Init() override;
    void Draw() override;
    void Update(float deltaTime) override;
    void HandleEvent(SDL_Event &event) override;

    ~LevelCompleteScene() override;
private:
    long m_TimeTookMillis = 0;
};


#endif //GOLFGAME_LEVELCOMPLETESCENE_H
