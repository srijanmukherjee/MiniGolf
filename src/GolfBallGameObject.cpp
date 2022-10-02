#include "GolfBallGameObject.h"

GolfBallGameObject::GolfBallGameObject(const char *textureSheet) : GameObject(textureSheet) {
    pos.x = 100;
    pos.y = 100;

    SDL_QueryTexture(m_ObjTexture, NULL, NULL, &m_SrcRect.w, &m_SrcRect.h);

    m_DestRect.w = 64;
    m_DestRect.h = 64;
}

GolfBallGameObject::~GolfBallGameObject() {
    spdlog::info("~GolfBallGameObject called");
}

void GolfBallGameObject::Update() {
    GameObject::Update();

    pos += GameMath::Vector2D(1, 1);
}
