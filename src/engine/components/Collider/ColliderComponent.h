#ifndef GOLFGAME_COLLIDERCOMPONENT_H
#define GOLFGAME_COLLIDERCOMPONENT_H

#include <SDL2/SDL_rect.h>
#include "../../ECS/ECS.h"
#include "../TransformComponent.h"

class ColliderComponent : public Component {
public:
    TransformComponent *transform = nullptr;
    SDL_Rect collider{};
    std::string tag{};

    explicit ColliderComponent(std::string &tag) {
        this->tag = tag;
    }

    void Init() override {
        if (!entity->HasComponent<TransformComponent>()) {
            entity->AddComponent<TransformComponent>();
        }

        transform = &entity->GetComponent<TransformComponent>();
    }

    void Update() override {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
};

#endif //GOLFGAME_COLLIDERCOMPONENT_H
