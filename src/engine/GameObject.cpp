#include "GameObject.h"

GameObject::GameObject(const char *textureSheet) {
    m_ObjTexture = TextureManager::LoadTexture(textureSheet);
}

GameObject::~GameObject() {
    SDL_DestroyTexture(m_ObjTexture);
}

void GameObject::Update() {

}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, m_ObjTexture, &m_SrcRect, &m_DestRect);
}
