#ifndef GOLFGAME_TRANSFORMCOMPONENT_H
#define GOLFGAME_TRANSFORMCOMPONENT_H

#include "../ECS/ECS.h"
#include "../../math/Vector2D.h"

using GameMath::Vector2D;

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    Vector2D rotationCenter;
    float rotation{};
    int width = 32;
    int height = 32;
    float scale = 1;

    TransformComponent() = default;
    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }
    TransformComponent(float x, float y, int w, int h, float sc) {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = sc;
    }

    void Update(float deltaTime) override {
        velocity += acceleration * deltaTime;
        position += velocity * deltaTime;
    }

    void SetRotation(float rot) {
        rotation = rot;
    }
};

#endif //GOLFGAME_TRANSFORMCOMPONENT_H
