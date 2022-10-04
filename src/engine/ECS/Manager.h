#ifndef GOLFGAME_MANAGER_H
#define GOLFGAME_MANAGER_H

#include "ECS.h"

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> m_Entities{};

public:
    void Update() {
        for (auto & e : m_Entities) {
            e->Update();
        }
    }

    void Draw() {
        for (auto & e : m_Entities) {
            e->Draw();
        }
    }

    void Refresh() {
        m_Entities.erase(
                std::remove_if(
                        std::begin(m_Entities),
                        std::end(m_Entities),
                        [](const std::unique_ptr<Entity> &entity) {
                            return !entity->IsActive();
                        }
                ),
                std::end(m_Entities));
    }

    template <typename... TArgs>
    Entity& AddEntity(TArgs... args) {
        auto *e = new Entity(std::forward<TArgs>(args)...);
        std::unique_ptr<Entity> uEntity { e };
        m_Entities.emplace_back(std::move(uEntity));
        return *e;
    }

    template <class T, typename... TArgs>
    T& AddEntity(TArgs... args) {
        Entity *e = new T(std::forward<TArgs>(args)...);
        std::unique_ptr<Entity> uEntity { e };
        m_Entities.emplace_back(std::move(uEntity));
        return *dynamic_cast<T*>(e);
    }
};

#endif //GOLFGAME_MANAGER_H
