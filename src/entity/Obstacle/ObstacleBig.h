#ifndef GOLFGAME_OBSTACLEBIG_H
#define GOLFGAME_OBSTACLEBIG_H

#include "Obstacle.h"
#include "../../engine/components/SpriteComponent.h"

class ObstacleBig : public Obstacle {
public:
    explicit ObstacleBig(void * scene) : Obstacle(scene) {
        auto &transform = GetComponent<TransformComponent>();
        transform.width = transform.height = 64;
        AddComponent<SpriteComponent>("obstacle_64.png");
    }
};

#endif //GOLFGAME_OBSTACLEBIG_H
