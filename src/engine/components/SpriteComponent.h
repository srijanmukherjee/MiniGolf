#ifndef GOLFGAME_SPRITECOMPONENT_H
#define GOLFGAME_SPRITECOMPONENT_H

#include "../ECS/ECS.h"
#include "TransformComponent.h"
#include "../TextureManager.h"
#include <SDL2/SDL.h>

class SpriteComponent : public Component {
public:
    SpriteComponent() = default;
    explicit SpriteComponent(const char * path) {
        SetTexture(path);
    }

    void SetTexture(const char * path) {
        if (m_Texture) SDL_DestroyTexture(m_Texture);
        m_Texture = TextureManager::LoadTexture(path);
    }

    void Init() override {
        m_Transform = &entity->GetComponent<TransformComponent>();
        m_SrcRect.x = m_SrcRect.y = 0;
        m_DestRect.w = m_Transform->width * m_Transform->scale;
        m_DestRect.h = m_Transform->height * m_Transform->scale;
        m_SrcRect.w = m_Transform->width;
        m_SrcRect.h = m_Transform->height;
    }

    void Update(float deltaTime) override {
        m_DestRect.x = (int) m_Transform->position.x;
        m_DestRect.y = (int) m_Transform->position.y;
        m_DestRect.w = m_Transform->width * m_Transform->scale;
        m_DestRect.h = m_Transform->height * m_Transform->scale;
    }

    void Draw() override {
        if (m_IsVisible) {
            SDL_Point center{ (int) m_Transform->rotationCenter.x, (int) m_Transform->rotationCenter.y };
            TextureManager::Draw(
                    m_Texture,
                    m_SrcRect,
                    m_DestRect,
                    m_Transform->rotation,
                    &center
            );
        }
    }

    void Show() {
        m_IsVisible = true;
    }

    void Hide() {
        m_IsVisible = false;
    }

    ~SpriteComponent() override {
        if (m_Texture) SDL_DestroyTexture(m_Texture);
    }
private:
    TransformComponent *m_Transform = nullptr;
    SDL_Texture *m_Texture = nullptr;
    SDL_Rect m_SrcRect{};
    SDL_Rect m_DestRect{};
    bool m_IsVisible = true;
};

#endif //GOLFGAME_SPRITECOMPONENT_H
