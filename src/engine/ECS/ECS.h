#ifndef GOLFGAME_ECS_H
#define GOLFGAME_ECS_H

#include <algorithm>
#include <bitset>
#include <vector>
#include <memory>
#include <array>
#include <stdexcept>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID() {
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept {
    static ComponentID typeID = GetComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitset = std::bitset<maxComponents>;
using ComponentList = std::vector<Component*>;


class Component {
public:
    Entity *entity{};

    virtual void Init() { };
    virtual void Update() { };
    virtual void Draw() { };
    virtual ~Component() = default;;
};

class Entity {
public:
    virtual void Update() {
        for (auto c : m_Components) {
            if (c == nullptr) continue;
            c->Update();
        }
    }

    virtual void Draw() {
        for (auto c : m_Components) {
            if (c == nullptr) continue;
            c->Draw();
        }
    }

    [[maybe_unused]] [[nodiscard]] bool IsActive() const {
        return m_Active;
    }

    void Destroy() {
        m_Active = false;
    }

    template <typename T> bool HasComponent() {
        return m_ComponentBitset[GetComponentTypeID<T>()];
    }

    template <class T, typename... TArgs>
    T& AddComponent(TArgs&&... args) {
        if (HasComponent<T>()) {
            throw std::runtime_error("Component already exists");
        }

        Component* component = new T(std::forward<TArgs>(args)...);
        component->entity = this;

        m_Components[GetComponentTypeID<T>()] = component;
        m_ComponentBitset[GetComponentTypeID<T>()] = true;

        component->Init();

        return *static_cast<T*>(component);
    }

    template <class T> T& GetComponent() {
        if (!HasComponent<T>()) {
            throw std::runtime_error("Component doesn't exist");
        }

        return *static_cast<T*>(m_Components[GetComponentTypeID<T>()]);
    }

    ~Entity() {
        for (auto c : m_Components) {
            delete c;
        }
    }
private:
    bool m_Active = true;
    ComponentList m_Components = std::vector<Component*>(maxComponents, nullptr);
    ComponentBitset m_ComponentBitset;
};

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> m_Entities;

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

    Entity& AddEntity() {
        auto *e = new Entity();
        std::unique_ptr<Entity> uEntity { e };
        m_Entities.emplace_back(std::move(uEntity));
        return *e;
    }

    template <class T>
    Entity& AddEntity() {
        Entity *e = new T();
        std::unique_ptr<Entity> uEntity { e };
        m_Entities.emplace_back(std::move(uEntity));
        return *e;
    }
};

#endif //GOLFGAME_ECS_H
