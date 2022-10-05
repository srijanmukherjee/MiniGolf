#ifndef GOLFGAME_GOALENTITY_H
#define GOLFGAME_GOALENTITY_H


#include "../CollidableEntity/CollidableEntity.h"

class GoalEntity : public CollidableEntity {
public:
    explicit GoalEntity(void * scene);
    GoalEntity(void * scene, int row, int col);
    void OnCollision(ColliderComponent &collider, float deltaTime) override;

private:
    TransformComponent *m_Transform = nullptr;
};

#endif //GOLFGAME_GOALENTITY_H
