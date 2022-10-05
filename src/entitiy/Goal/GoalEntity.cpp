#include "GoalEntity.h"
#include "../../engine/components/SpriteComponent.h"

GoalEntity::GoalEntity(void *scene) : CollidableEntity(scene, "goal") {
    m_Transform = &GetComponent<TransformComponent>();
    m_Transform->width = m_Transform->height = 18;
    AddComponent<SpriteComponent>("../assets/textures/goal.png");
}

GoalEntity::GoalEntity(void *scene, int row, int col) : GoalEntity(scene) {
    int w = 32;
    int h = 32;
    int offset_x = (w - 18) / 2;
    int offset_y = (h - 18) / 2;
    m_Transform->position.x = w * col + offset_x;
    m_Transform->position.y = h * row + offset_y;
}

void GoalEntity::OnCollision(ColliderComponent &collider, float deltaTime) {

}
