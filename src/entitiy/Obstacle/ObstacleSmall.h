#ifndef GOLFGAME_OBSTACLESMALL_H
#define GOLFGAME_OBSTACLESMALL_H

#include "Obstacle.h"
#include "../../engine/components/SpriteComponent.h"

class ObstacleSmall : public Obstacle {
public:
    explicit ObstacleSmall(void * scene) : Obstacle(scene) {
        auto &transform = GetComponent<TransformComponent>();
        transform.width = transform.height = 32;
        AddComponent<SpriteComponent>("obstacle_32.png");
    }
};

#endif //GOLFGAME_OBSTACLESMALL_H
