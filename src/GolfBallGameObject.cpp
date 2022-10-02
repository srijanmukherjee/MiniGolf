#include "GolfBallGameObject.h"
#include "math/Math.h"

GolfBallGameObject::GolfBallGameObject(const char *textureSheet) : GameObject(textureSheet) {
    SDL_QueryTexture(m_ObjTexture, nullptr, nullptr, &m_SrcRect.w, &m_SrcRect.h);
    m_DestRect.w = 32;
    m_DestRect.h = 32;
    m_Pos.y = 320;
    m_Pos.x = 50;
}

GolfBallGameObject::~GolfBallGameObject() {
    spdlog::info("~GolfBallGameObject called");
}

void GolfBallGameObject::Update() {
    GameObject::Update();

    m_Pos.x += m_Velocity.x;
    m_Pos.y += m_Velocity.y;
    m_DestRect.x = m_Pos.x;
    m_DestRect.y = m_Pos.y;
    m_Velocity *= (1 - m_Friction);

    if (m_Velocity.Magnitude2() < 1) m_Velocity *= 0;
}

void GolfBallGameObject::Hold() {
    // ball is still moving can't hold it
    if (m_Velocity.Magnitude2() != 0) return;

    int mx, my;
    Uint32 buttons = SDL_GetMouseState(&mx, &my);


    if ((buttons & SDL_BUTTON_LMASK) != 0) {
        m_IsHolding = true;
    }
}

void GolfBallGameObject::Release() {
    if (!m_IsHolding) return;

    SDL_PumpEvents();
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    GameMath::Vector2D mousePos{mx, my};

    // magnitude of velocity
    double dist = m_Pos.dist2(mousePos);
    dist = std::clamp<double>(dist, 0, MAX_STRETCH);

    int launchPower = (int) GameMath::Map(dist, 0, MAX_STRETCH, 0, MAX_SPEED);
    spdlog::info("Launch power: {}", launchPower);

    // direction of velocity
    GameMath::Vector2D newVelocity = (m_Pos - mousePos).UnitVector() * launchPower;
    m_Velocity.x = newVelocity.x;
    m_Velocity.y = newVelocity.y;

    spdlog::info("velocity = {} + {}", newVelocity.x, newVelocity.y);

    m_IsHolding = false;
}
