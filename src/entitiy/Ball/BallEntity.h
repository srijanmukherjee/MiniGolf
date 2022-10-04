//
// Created by srijan on 10/3/22.
//

#ifndef GOLFGAME_BALLENTITY_H
#define GOLFGAME_BALLENTITY_H


#include "../../engine/ECS/ECS.h"
#include "../../engine/components/TransformComponent.h"
#include "../../engine/components/SpriteComponent.h"
#include "../CollidableEntity/CollidableEntity.h"

class BallEntity : public CollidableEntity {
public:
    BallEntity(void * scene);

    void OnMouseMove();
    void OnMouseDown();
    void OnMouseUp();

    void Update() override;
    void OnCollision(ColliderComponent &collider) override;

private:
    const int MAX_STRETCH = 95000;
    const int MAX_SPEED = 40;

    TransformComponent *m_Transform;
    bool m_IsHolding = false;
    float m_Friction = 0.01;
};


#endif //GOLFGAME_BALLENTITY_H
