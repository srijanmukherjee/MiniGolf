#ifndef GOLFGAME_COLLIDABLEENTITY_H
#define GOLFGAME_COLLIDABLEENTITY_H


#include "../../engine/ECS/ECS.h"
#include "../../engine/components/Collider/ColliderComponent.h"


class CollidableEntity : public Entity {
public:
    CollidableEntity() : CollidableEntity("collider") { }

    explicit CollidableEntity(std::string tag) {
        AddComponent<ColliderComponent>(tag);

    }

    virtual void OnCollision(ColliderComponent &collider) = 0;
};

#endif //GOLFGAME_COLLIDABLEENTITY_H
