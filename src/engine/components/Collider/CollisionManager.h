#ifndef GOLFGAME_COLLISIONMANAGER_H
#define GOLFGAME_COLLISIONMANAGER_H

#include <spdlog/spdlog.h>
#include <vector>

#include "../../ECS/ECS.h"
#include "../../../entity/CollidableEntity/CollidableEntity.h"

#include "Collision.h"

class CollisionManager {
public:
    void ListenForCollision(CollidableEntity *entity) {
        m_Entities.push_back(entity);
    }

    void StartDetectingCollision() {
        m_Listening = true;
    }

    void Update(float deltaTime) {
        if (!m_Listening) return;

        for (auto e1 : m_Entities) {
            for (auto e2 : m_Entities) {
                if (e1 == e2) continue;

                if (Collision::AABB(*e1, *e2, deltaTime)) {
                    e1->OnCollision(e2->GetComponent<ColliderComponent>(), deltaTime);
                }
            }
        }
    }

private:
    std::vector<CollidableEntity*> m_Entities{};
    bool m_Listening = false;
};


#endif //GOLFGAME_COLLISIONMANAGER_H
