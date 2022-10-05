#include "WallEntity.h"

WallEntity::WallEntity(void * scene, const std::string &tag) : CollidableEntity(scene, tag) { }

WallEntity::WallEntity(void * scene, const std::string &tag, const SDL_Rect &dimension) : WallEntity(scene, tag) {
    auto &transform = GetComponent<TransformComponent>();
    transform.position.x    = (float) dimension.x;
    transform.position.y    = (float) dimension.y;
    transform.width         = dimension.w;
    transform.height        = dimension.h;
}

void WallEntity::OnCollision(ColliderComponent &collider, float deltaTime) {

}
