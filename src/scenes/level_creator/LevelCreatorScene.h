#ifndef GOLFGAME_LEVELCREATORSCENE_H
#define GOLFGAME_LEVELCREATORSCENE_H


#include <map>
#include "../../engine/Scene.h"
#include "../../GolfTileMap.h"
#include "../../entity/Ball/BallEntity.h"
#include "../../entity/Goal/GoalEntity.h"
#include "../../entity/Obstacle/Obstacle.h"

enum GameComponent { OBSTACLE_SM, OBSTACLE_LG, BALL, GOAL };


class LevelCreatorScene : public Scene {
public:
    void Init() override;
    void HandleEvent(SDL_Event &event) override;

private:
    GolfTileMap *tileMap = nullptr;
    BallEntity *m_BallEntity = nullptr;
    GoalEntity *m_GoalEntity = nullptr;
    std::map<std::pair<int, int>, Obstacle*> m_ObstaclesSmall;
    std::map<std::pair<int, int>, Obstacle*> m_ObstaclesBig;

    GameComponent m_SelectedComponent = GameComponent::BALL;

    void PlaceComponent();

    void ChangeComponent(const SDL_KeyboardEvent &key);

    void Export();
};


#endif //GOLFGAME_LEVELCREATORSCENE_H
