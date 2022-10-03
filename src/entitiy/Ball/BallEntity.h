//
// Created by srijan on 10/3/22.
//

#ifndef GOLFGAME_BALLENTITY_H
#define GOLFGAME_BALLENTITY_H


#include "../../engine/ECS/ECS.h"
#include "../../components/TransformComponent.h"
#include "../../components/SpriteComponent.h"

class BallEntity : public Entity {
public:
    BallEntity();

    void OnMouseMove();
    void OnMouseDown();
    void OnMouseUp();

    void Update() override;

private:
    const int MAX_STRETCH = 95000;
    const int MAX_SPEED = 40;

    TransformComponent *m_Transform;
    bool m_IsHolding = false;
    float m_Friction = 0.01;
};


#endif //GOLFGAME_BALLENTITY_H
