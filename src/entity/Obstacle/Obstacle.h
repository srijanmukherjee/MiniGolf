#ifndef GOLFGAME_OBSTACLE_H
#define GOLFGAME_OBSTACLE_H


#include "../CollidableEntity/CollidableEntity.h"

class Obstacle : public CollidableEntity {
public:
    explicit Obstacle(void *scene);
    void SetPosition(int x, int y);

    void OnCollision(ColliderComponent &collider, float deltaTime) override;
};


#endif //GOLFGAME_OBSTACLE_H
