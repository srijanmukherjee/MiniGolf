#ifndef GOLFGAME_GAMEOBJECT_H
#define GOLFGAME_GAMEOBJECT_H

#include "Game.h"

class GameObject {
public:
    GameObject() = default;
    explicit GameObject(const char* textureSheet);
    ~GameObject();

    virtual void Update(float deltaTime);
    virtual void Render();

protected:
    SDL_Texture* m_ObjTexture;
    SDL_Rect m_SrcRect{};
    SDL_Rect m_DestRect{};
};

#endif //GOLFGAME_GAMEOBJECT_H
