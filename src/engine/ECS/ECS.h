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
    virtual void Update(float deltaTime) { };
    virtual void Draw() { };
    virtual ~Component() = default;;
};

class Entity {
public:
    void *scene;

    explicit Entity(void *scene) : scene(scene) {}

    virtual void Update(float deltaTime) {
        for (auto c : m_Components) {
            if (c == nullptr) continue;
            c->Update(deltaTime);
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

    virtual ~Entity() {
        for (auto c : m_Components) {
            delete c;
        }
    }
private:
    bool m_Active = true;
    ComponentList m_Components = std::vector<Component*>(maxComponents, nullptr);
    ComponentBitset m_ComponentBitset;
};

#endif //GOLFGAME_ECS_H
