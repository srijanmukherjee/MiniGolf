#include "BallEntity.h"

#include "../../res/Constant.h"
#include "../../math/Math.h"

#include "DirectionComponent.h"
#include "PowerBarComponent.h"

Vector2D startPos;

BallEntity::BallEntity(void * scene) : CollidableEntity(scene, "ball") {
    m_Transform = &GetComponent<TransformComponent>();
    m_Transform->position.x = 50;
    m_Transform->position.y = 150;
    m_Transform->width = 16;
    m_Transform->height = 16;
    AddComponent<SpriteComponent>("ball_2.png");
    AddComponent<DirectionComponent>(10).Hide();
    AddComponent<PowerBarComponent>(scene, MAX_SPEED).Hide();
}

void BallEntity::OnMouseDown() {
    // can't shoot the ball when it's moving
    if (m_Transform->velocity.Magnitude() >= 15 || m_HasWon) return;

    int mx, my;
    Uint32 buttons = SDL_GetMouseState(&mx, &my);

    if ((buttons & SDL_BUTTON_LMASK) != 0) {
        startPos.x = (float) mx;
        startPos.y = (float) my;
        m_IsHolding = true;
    }
}

void BallEntity::OnMouseUp() {
    if (!m_IsHolding || m_HasWon) return;

    SDL_PumpEvents();
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    GameMath::Vector2D mousePos{mx, my};

    m_Transform->velocity = (startPos - mousePos).UnitVector() * m_LaunchPower;
    m_IsHolding = false;

    GetComponent<DirectionComponent>().Hide();
    GetComponent<PowerBarComponent>().Hide();
}

void BallEntity::OnMouseMove() {
    if (m_HasWon) return;

    if (m_IsHolding) {
        SDL_PumpEvents();
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        GameMath::Vector2D mousePos{mx, my};

        double dist = mousePos.dist2(startPos);
        dist = std::clamp<double>(dist, 0, MAX_STRETCH);
        m_LaunchPower = (float) GameMath::Map(dist, 0, MAX_STRETCH, 0, MAX_SPEED - MIN_SPEED) + MIN_SPEED;

        GetComponent<DirectionComponent>().PointTowards(startPos - mousePos, m_Transform->position + Vector2D(8, 8));
        GetComponent<DirectionComponent>().Show();
        GetComponent<PowerBarComponent>().SetPosition(m_Transform->position + Vector2D(16 + 24, -16));
        GetComponent<PowerBarComponent>().SetValue((int) m_LaunchPower);
        GetComponent<PowerBarComponent>().Show();
    }
}

void BallEntity::Update(float deltaTime) {
    Entity::Update(deltaTime);

    // make sure ball stays within bounds
    int w = m_Transform->width * m_Transform->scale;
    int h = m_Transform->height * m_Transform->scale;
    if (m_Transform->position.x + w > Constant::SCREEN_WIDTH) m_Transform->position.x = Constant::SCREEN_WIDTH - w - 1;
    if (m_Transform->position.x < 0) m_Transform->position.x = 1;
    if (m_Transform->position.y + h > Constant::SCREEN_WIDTH) m_Transform->position.y = Constant::SCREEN_HEIGHT - h - 1;
    if (m_Transform->position.y < 0) m_Transform->position.y = 1;

    float mag = m_Transform->velocity.Magnitude();
    m_Transform->velocity = m_Transform->velocity.UnitVector() * mag * ( 1 - m_Friction * deltaTime );

    if (m_Transform->velocity.Magnitude() < 20) {
        m_Transform->velocity *= 0;
    }

    // reduce scale to simulate the ball going inside the goal hole
    if (m_HasWon && m_Transform->scale > 0) {
        m_Transform->scale -= 0.02; // 0.98
        m_Transform->position += Vector2D(
                static_cast<float>(m_Transform->width) * 0.02f / 2,
                static_cast<float>(m_Transform->height) * 0.02f / 2);
        if (m_Transform->scale <= 0) {
            m_Transform->scale = 0;
            m_InsideGoal = true;
        }
    }
}

void BallEntity::OnCollision(ColliderComponent &collider, float deltaTime) {
    if (collider.tag == "wall_horizontal") {
        m_Transform->velocity.y *= -1;
        m_Transform->position.y += m_Transform->velocity.y * deltaTime;
    } else if (collider.tag == "wall_vertical") {
        m_Transform->velocity.x *= -1;
        m_Transform->position.x += m_Transform->velocity.x * deltaTime;
    } else if (collider.tag == "obstacle") {
        Vector2D pos = collider.transform->position;
        int w = collider.transform->width;
        int h = collider.transform->height;

        // horizontal side of the obstacle
        if ((m_Transform->position.x >= pos.x && m_Transform->position.x <= pos.x + w) ||
            ((m_Transform->position.x + m_Transform->width >= pos.x && m_Transform->position.x + m_Transform->width <= pos.x + w))) {
            m_Transform->velocity.y *= -1;
            m_Transform->position.y += m_Transform->velocity.y * deltaTime;
        }

        // vertical side of the obstacle
        if ((m_Transform->position.y >= pos.y && m_Transform->position.y <= pos.y + h) ||
            (m_Transform->position.y + m_Transform->height >= pos.y && m_Transform->position.y + m_Transform->height <= pos.y + h)) {

            m_Transform->velocity.x *= -1;
            m_Transform->position.x += m_Transform->velocity.x * deltaTime;
        }
    } else if (collider.tag == "goal" && !m_HasWon && m_Transform->velocity.Magnitude() < MAX_SPEED * 0.8) {
        Vector2D goalCenter = collider.transform->position + Vector2D(9, 9);
        Vector2D ballCenter = m_Transform->position + Vector2D(8, 8);

        if ((ballCenter - goalCenter).Magnitude() < 10) {
            m_HasWon = true;
            m_Transform->velocity *= 0;
            m_Transform->position = goalCenter - Vector2D(8, 8);
        }
    }
}
