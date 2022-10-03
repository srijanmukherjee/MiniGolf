#ifndef GOLFGAME_TRANSFORMCOMPONENT_H
#define GOLFGAME_TRANSFORMCOMPONENT_H

#include "../engine/ECS/ECS.h"
#include "../math/Vector2D.h"

using GameMath::Vector2D;

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    Vector2D rotationCenter;
    float rotation{};

    TransformComponent() = default;
    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    void Update() override {
        velocity += acceleration;
        position += velocity;
    }

    void SetRotation(float rot) {
        rotation = rot;
    }
};

#endif //GOLFGAME_TRANSFORMCOMPONENT_H
