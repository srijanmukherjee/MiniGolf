#ifndef GOLFGAME_COLLISION_H
#define GOLFGAME_COLLISION_H


#include "../../ECS/ECS.h"

class Collision {
public:
    static bool AABB(Entity &a, Entity &b, float deltaTime);
};


#endif //GOLFGAME_COLLISION_H
