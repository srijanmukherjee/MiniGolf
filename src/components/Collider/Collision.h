#ifndef GOLFGAME_COLLISION_H
#define GOLFGAME_COLLISION_H


#include "../../engine/ECS/ECS.h"

class Collision {
public:
    static bool AABB(Entity &a, Entity &b);
};


#endif //GOLFGAME_COLLISION_H
