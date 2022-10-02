#ifndef GOLFGAME_GOLFBALLGAMEOBJECT_H
#define GOLFGAME_GOLFBALLGAMEOBJECT_H

#include "engine/GameObject.h"
#include "math/Vector2D.h"

class GolfBallGameObject : public GameObject {
public:
    explicit GolfBallGameObject(const char *textureSheet);
    ~GolfBallGameObject();
    void Update() override;

    void Hold();
    void Release();
private:
    GameMath::Vector2D m_Pos{};
    GameMath::Vector2D m_Velocity{};
    float m_Friction = .08;
    bool m_IsHolding = false;

    const int MAX_STRETCH = 90000;
    const int MAX_SPEED = 50;
};


#endif //GOLFGAME_GOLFBALLGAMEOBJECT_H
