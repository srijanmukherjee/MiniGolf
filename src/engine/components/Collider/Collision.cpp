#include "Collision.h"
#include "ColliderComponent.h"

bool Collision::AABB(Entity &a, Entity &b) {
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
    rectA.x += (int)transformA.velocity.x;
    rectA.y += (int)transformA.velocity.y;
    rectB.x += (int)transformB.velocity.x;
    rectB.y += (int)transformB.velocity.y;

    return rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x &&
            rectA.y + rectA.h >= rectB.y && rectB.y + rectB.h >= rectA.y;
}
