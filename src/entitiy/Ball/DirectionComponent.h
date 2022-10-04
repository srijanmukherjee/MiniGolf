#ifndef GOLFGAME_DIRECTIONCOMPONENT_H
#define GOLFGAME_DIRECTIONCOMPONENT_H

#include "../../engine/ECS/ECS.h"
#include "../../engine/components/SpriteComponent.h"

#include <cmath>

class DirectionComponent : public Entity, public Component {
public:
    explicit DirectionComponent(float radius) : m_Radius(radius), Entity(nullptr) { }

    void Init() override {
        m_Transform = &AddComponent<TransformComponent>();
        m_Sprite = &AddComponent<SpriteComponent>("../assets/textures/arrow.png");
    }

    void Update(float deltaTime) override {
        Entity::Update(deltaTime);
    }

    void Draw() override {
        Entity::Draw();
    }

    void PointTowards(const Vector2D& dir, const Vector2D& center) {
        Vector2D straight = (Vector2D(center.x, 0.0) - center).UnitVector();
        int angle = (int) (dir.angleBetween(straight) * 180 / M_PI);

        if (dir.x < 0) {
            angle *= -1;
        }
        RotateAboutBy(center, angle);
    }

    void Show() {
        m_Sprite->Show();
    }

    void Hide() {
        m_Sprite->Hide();
    }
private:
    SpriteComponent *m_Sprite = nullptr;
    TransformComponent *m_Transform = nullptr;
    float m_Radius = 0;

    void RotateAboutBy(const Vector2D& mid, int rot) {
        m_Transform->position.x = (float) (mid.x - 16 * std::cos(rot * M_PI / 180) + (m_Radius + 16) * std::cos((90 - rot) * M_PI / 180));
        m_Transform->position.y = (float) (mid.y - 16 * std::cos((90 - rot) * M_PI / 180) - (m_Radius + 16) * std::cos(rot * M_PI / 180));
        m_Transform->SetRotation((float) rot);
    }
};

#endif //GOLFGAME_DIRECTIONCOMPONENT_H
