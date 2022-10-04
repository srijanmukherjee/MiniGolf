#include "Collision.h"
#include "ColliderComponent.h"

bool Collision::AABB(Entity &a, Entity &b, float deltaTime) {
    if (!a.HasComponent<ColliderComponent>()) {
        throw std::invalid_argument("Entity (a) must have a collider component");
    }

    if (!b.HasComponent<ColliderComponent>()) {
        throw std::invalid_argument("Entity (b) must have a collider component");
    }

    auto rectA = a.GetComponent<ColliderComponent>().collider;
    auto rectB = b.GetComponent<ColliderComponent>().collider;
    auto &transformA = a.GetComponent<TransformComponent>();
    auto &transformB = b.GetComponent<TransformComponent>();

    // project the rect by the velocity to detect possible collision in the next frame
    rectA.x += transformA.velocity.x * deltaTime;
    rectA.y += transformA.velocity.y * deltaTime;
    rectB.x += transformB.velocity.x * deltaTime;
    rectB.y += transformB.velocity.y * deltaTime;

    return rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x &&
            rectA.y + rectA.h >= rectB.y && rectB.y + rectB.h >= rectA.y;
}
