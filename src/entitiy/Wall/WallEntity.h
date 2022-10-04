#ifndef GOLFGAME_WALLENTITY_H
#define GOLFGAME_WALLENTITY_H


#include "../CollidableEntity/CollidableEntity.h"

class WallEntity : public CollidableEntity {
public:
    explicit WallEntity(void * scene, const std::string &tag);
    WallEntity(void * scene, const std::string &tag, const SDL_Rect &dimension);
    void OnCollision(ColliderComponent &collider) override;
};


#endif //GOLFGAME_WALLENTITY_H
