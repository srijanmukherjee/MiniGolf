#include "Obstacle.h"

Obstacle::Obstacle(void *scene) : CollidableEntity(scene, "obstacle") { }

void Obstacle::SetPosition(int x, int y) {
    auto &transform = GetComponent<TransformComponent>();
    transform.position.x = (float) x;
    transform.position.y = (float) y;
}

void Obstacle::OnCollision(ColliderComponent &collider, float deltaTime) { }
