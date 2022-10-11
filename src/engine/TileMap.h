#ifndef GOLFGAME_TILEMAP_H
#define GOLFGAME_TILEMAP_H

#include <vector>

#include "Game.h"
#include "ECS/ECS.h"

class TileMap : public Entity {
public:
    explicit TileMap(void * scene);
    ~TileMap() override;

    void Draw() override;
protected:
    void LoadMap(const std::vector<std::vector<int>> &map, int tileSize);
    void LoadTextures(const std::vector<const char *> &textures, const SDL_Rect &rect);
    void CleanTextures();

    SDL_Rect m_DestRect, m_SrcRect;
    std::vector<std::vector<int>> m_TileMap;
    std::vector<SDL_Texture *> m_Textures;
    int m_TileSize{};
};


#endif //GOLFGAME_TILEMAP_H
