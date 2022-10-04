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
    Vector2D posA = transformA.position;
    Vector2D posB = transformB.position;
    // project the rect by the velocity to detect possible collision in the next frame
    posA += transformA.velocity * deltaTime;
    posB += transformB.velocity * deltaTime;
    rectA.x = posA.x;
    rectA.y = posA.y;
    rectB.x = posB.x;
    rectB.y = posB.y;

    return rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x &&
            rectA.y + rectA.h >= rectB.y && rectB.y + rectB.h >= rectA.y;
}
