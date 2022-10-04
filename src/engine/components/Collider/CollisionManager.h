#ifndef GOLFGAME_COLLISIONMANAGER_H
#define GOLFGAME_COLLISIONMANAGER_H

#include <vector>
#include "../../../entitiy/CollidableEntity/CollidableEntity.h"

class CollisionManager {
public:
    void ListenForCollision(CollidableEntity *entity) {
        m_Entities.push_back(entity);
    }

    void Update() {

    }

private:
    std::vector<CollidableEntity*> m_Entities;
};


#endif //GOLFGAME_COLLISIONMANAGER_H
