#include "ClockEntity.h"
#include "../../engine/Game.h"
#include "../../engine/components/TransformComponent.h"

#include <iomanip>
#include <sstream>

ClockEntity::ClockEntity(void *scene, long initialTimeMillis)
    : Entity(scene), m_initialTimeMillis(initialTimeMillis) {
    m_Font = TTF_OpenFont("./assets/fonts/alarm clock.ttf", 48);
    m_StartTime = std::chrono::steady_clock::now();

    AddComponent<TransformComponent>();
}

void ClockEntity::Update(float deltaTime) {
    Entity::Update(deltaTime);

    auto elapsedTime = static_cast<double>(GetElapsedTime()); // Millis
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << elapsedTime / 1000.0;
    auto str = ss.str();
    m_Surface = TTF_RenderText_Solid(m_Font, str.c_str(), { 255, 255, 255 });
    m_Texture = SDL_CreateTextureFromSurface(Game::renderer, m_Surface);

    int w, h;
    TTF_SizeText(m_Font, str.c_str(), &w, &h);

    auto transform = GetComponent<TransformComponent>();

    int x = static_cast<int>(transform.position.x) - w;
    int y = static_cast<int>(transform.position.y);
    m_Rect = { x, y, w, h };

    SDL_FreeSurface(m_Surface);
    m_Surface = nullptr;
}

void ClockEntity::Draw() {
    Entity::Draw();
    SDL_RenderCopy(Game::renderer, m_Texture, nullptr, &m_Rect);
    SDL_DestroyTexture(m_Texture);
    m_Texture = nullptr;
}

long ClockEntity::GetElapsedTime() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - m_StartTime).count() + m_initialTimeMillis;
}

ClockEntity::~ClockEntity() {
    if (m_Surface != nullptr) SDL_FreeSurface(m_Surface);
    if (m_Surface != nullptr) SDL_DestroyTexture(m_Texture);
    TTF_CloseFont(m_Font);
}
