#include "Scene.h"

void Scene::Update() {
    m_CollisionManager.Update();
    m_Manager.Update();
}

void Scene::Draw() {
    m_Manager.Draw();
}

void Scene::HandleEvent(SDL_Event &event) { }
