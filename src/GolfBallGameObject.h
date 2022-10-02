#ifndef GOLFGAME_GOLFBALLGAMEOBJECT_H
#define GOLFGAME_GOLFBALLGAMEOBJECT_H

#include "engine/GameObject.h"
#include "math/Vector2D.h"

class GolfBallGameObject : public GameObject {
public:
    explicit GolfBallGameObject(const char *textureSheet);
    ~GolfBallGameObject();

    void Update() override;
private:
    GameMath::Vector2D pos;
};


#endif //GOLFGAME_GOLFBALLGAMEOBJECT_H
