#include "CollidableEntity.h"
#include "../../engine/Scene.h"

CollidableEntity::CollidableEntity(void *scene, const std::string &tag): Entity(scene) {
    AddComponent<ColliderComponent>(tag);
    static_cast<Scene*>(scene)->GetCollisionManager().ListenForCollision(this);
}
