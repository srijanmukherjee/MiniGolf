#ifndef GOLFGAME_CLOCKENTITY_H
#define GOLFGAME_CLOCKENTITY_H

#include "../../engine/ECS/ECS.h"

#include <SDL2/SDL_ttf.h>
#include <chrono>


class ClockEntity : public Entity {
public:
    explicit ClockEntity(void * scene, long initialTimeMillis = 0);
    void Update(float deltaTime) override;
    void Draw() override;

    [[nodiscard]] long GetElapsedTime() const;

    ~ClockEntity() override;
private:
    long m_initialTimeMillis = 0;
    std::chrono::steady_clock::time_point m_StartTime;

    TTF_Font *m_Font = nullptr;
    SDL_Surface *m_Surface = nullptr;
    SDL_Texture *m_Texture = nullptr;
    SDL_Rect m_Rect;
};


#endif //GOLFGAME_CLOCKENTITY_H
