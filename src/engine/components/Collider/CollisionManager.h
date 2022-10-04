#ifndef GOLFGAME_COLLISIONMANAGER_H
#define GOLFGAME_COLLISIONMANAGER_H

#include <vector>
#include "../../ECS/ECS.h"
#include "../../../entitiy/CollidableEntity/CollidableEntity.h"
#include "Collision.h"

class CollisionManager {
public:
    void ListenForCollision(CollidableEntity *entity) {
        m_Entities.push_back(entity);
    }

    void Update() {
        for (auto e1 : m_Entities) {
            for (auto e2 : m_Entities) {
                if (e1 == e2) continue;

                if (Collision::AABB(*e1, *e2)) {
                    e1->OnCollision(e2->GetComponent<ColliderComponent>());
                }
            }
        }
    }

private:
    std::vector<CollidableEntity*> m_Entities{};
};


#endif //GOLFGAME_COLLISIONMANAGER_H
