#include "Scene.h"

void Scene::Update(float deltaTime) {
    m_CollisionManager.Update(deltaTime);
    m_Manager.Update(deltaTime);
}

void Scene::Draw() {
    m_Manager.Draw();
}

void Scene::HandleEvent(SDL_Event &event) { }
