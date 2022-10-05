#ifndef GOLFGAME_POWERBARCOMPONENT_H
#define GOLFGAME_POWERBARCOMPONENT_H

#include "../../engine/ECS/ECS.h"
#include "../../math/Vector2D.h"
#include "../../engine/components/SpriteComponent.h"

using GameMath::Vector2D;

class PowerBarComponent : public Component, public Entity {
public:
    explicit PowerBarComponent(void *scene, int maxValue)
        : Entity(scene), m_MaxValue(maxValue), m_Rect({ 0, 0, 0, 0 }) {
        AddComponent<TransformComponent>(0, 0, WIDTH, HEIGHT, 1);
        AddComponent<SpriteComponent>("../assets/textures/powerbar_bg.png");
        m_Rect.w = WIDTH - 2 * PADDING;
    }

    void Update(float deltaTime) override {
        Entity::Update(deltaTime);
    }

    void Draw() override {
        Entity::Draw();

        if (!m_Hidden) {
            SDL_SetRenderDrawColor(Game::renderer, 216, 238, 37, 255);
            SDL_RenderFillRect(Game::renderer, &m_Rect);
        }
    }

    void SetPosition(const Vector2D& pos) {
        GetComponent<TransformComponent>().position = pos;
        m_Rect.x = (int) pos.x + PADDING;
    }

    void SetValue(int value) {
        if (value > m_MaxValue) value = m_MaxValue;
        int maxHeight = HEIGHT - 2 * PADDING;
        m_Rect.h = (value / (float) m_MaxValue) * maxHeight;
        m_Rect.y = GetComponent<TransformComponent>().position.y +  PADDING + (maxHeight - m_Rect.h);
    }

    void Show() {
        GetComponent<SpriteComponent>().Show();
        m_Hidden = false;
    }

    void Hide() {
        GetComponent<SpriteComponent>().Hide();
        m_Hidden = true;
    }

private:
    int m_MaxValue = 0;
    bool m_Hidden = false;
    SDL_Rect m_Rect{};
    const int HEIGHT = 48;
    const int WIDTH = 10;
    const int PADDING = 2;
};

#endif //GOLFGAME_POWERBARCOMPONENT_H
