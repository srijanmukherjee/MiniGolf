#include <iostream>
#include "BallEntity.h"
#include "../../math/Math.h"
#include "DirectionComponent.h"

Vector2D startPos;

BallEntity::BallEntity(void * scene) : CollidableEntity(scene, "ball") {
    AddComponent<SpriteComponent>("../assets/textures/ball.png");
    AddComponent<DirectionComponent>(20).Hide();
    m_Transform = &GetComponent<TransformComponent>();
    m_Transform->position.x = 50;
    m_Transform->position.y = 150;
}

void BallEntity::OnMouseDown() {
    // can't shoot the ball when it's moving
    if (m_Transform->velocity.Magnitude2() != 0) return;

    int mx, my;
    Uint32 buttons = SDL_GetMouseState(&mx, &my);

    if ((buttons & SDL_BUTTON_LMASK) != 0) {
        startPos.x = (float) mx;
        startPos.y = (float) my;
        m_IsHolding = true;
    }
}

void BallEntity::OnMouseUp() {
    if (!m_IsHolding) return;

    SDL_PumpEvents();
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    GameMath::Vector2D mousePos{mx, my};

    if (startPos == mousePos) {
        m_IsHolding = false;
        GetComponent<DirectionComponent>().Hide();
        return;
    }

    // magnitude of velocity
    double dist = mousePos.dist2(startPos);
    dist = std::clamp<double>(dist, 0, MAX_STRETCH);

    auto launchPower = (float) GameMath::Map(dist, 0, MAX_STRETCH, 0, MAX_SPEED);

    // direction of velocity
    GameMath::Vector2D newVelocity = (startPos - mousePos).UnitVector() * launchPower;
    m_Transform->velocity.x = newVelocity.x;
    m_Transform->velocity.y = newVelocity.y;
    m_IsHolding = false;
    GetComponent<DirectionComponent>().Hide();
}

void BallEntity::OnMouseMove() {

    if (m_IsHolding) {
        SDL_PumpEvents();
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        GameMath::Vector2D mousePos{mx, my};

        GetComponent<DirectionComponent>().PointTowards(startPos - mousePos, m_Transform->position + Vector2D(16, 16));
        GetComponent<DirectionComponent>().Show();
    }
}

void BallEntity::Update() {
    Entity::Update();

    m_Transform->velocity *= (1 - m_Friction);

    if (m_Transform->velocity.Magnitude() < 0.8) {
        m_Transform->velocity *= 0;
    }
}

void BallEntity::OnCollision(ColliderComponent &collider) {
    if (collider.tag == "wall_horizontal") {
        m_Transform->velocity.y *= -1;
        m_Transform->position.y += m_Transform->velocity.y;
    } else if (collider.tag == "wall_vertical") {
        m_Transform->velocity.x *= -1;
        m_Transform->position.x += m_Transform->velocity.x;
    }
}
