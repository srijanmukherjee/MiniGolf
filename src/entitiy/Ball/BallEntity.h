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
    explicit BallEntity(void * scene);

    void OnMouseMove();
    void OnMouseDown();
    void OnMouseUp();

    void Update(float deltaTime) override;
    void OnCollision(ColliderComponent &collider, float deltaTime) override;

private:
    const int MAX_STRETCH = 95000;
    const int MAX_SPEED = 1500;

private:
    TransformComponent *m_Transform;
    bool m_IsHolding = false;
    bool m_HasWon = false;
    float m_Friction = 0.99;
    float m_LaunchPower = 0;
};


#endif //GOLFGAME_BALLENTITY_H
