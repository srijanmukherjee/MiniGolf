#ifndef GOLFGAME_COLLIDABLEENTITY_H
#define GOLFGAME_COLLIDABLEENTITY_H


#include "../../engine/ECS/ECS.h"
#include "../../engine/components/Collider/ColliderComponent.h"

class CollidableEntity : public Entity {
public:
    explicit CollidableEntity(void * scene) : CollidableEntity(scene, "collider") { }
    CollidableEntity(void * scene, const std::string& tag);

    virtual void OnCollision(ColliderComponent &collider, float deltaTime) = 0;
};

#endif //GOLFGAME_COLLIDABLEENTITY_H
