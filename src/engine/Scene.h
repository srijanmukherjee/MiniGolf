#ifndef GOLFGAME_SCENE_H
#define GOLFGAME_SCENE_H

#include "ECS/Manager.h"
#include "components/Collider/CollisionManager.h"

#include <SDL2/SDL.h>

class Scene {
public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void Update();
    virtual void Draw();
    virtual void HandleEvent(SDL_Event &event);
    virtual void Init() { };

    CollisionManager& GetCollisionManager() { return m_CollisionManager; }

protected:
    Manager m_Manager;
    CollisionManager m_CollisionManager;
};


#endif //GOLFGAME_SCENE_H
