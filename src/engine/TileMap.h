#ifndef GOLFGAME_TILEMAP_H
#define GOLFGAME_TILEMAP_H

#include <vector>

#include "Game.h"

class TileMap {
public:
    ~TileMap();
    virtual void RenderMap();

protected:
    void LoadMap(const std::vector<std::vector<int>>& map, int tileSize);
    void LoadTextures(const std::vector<const char *>& textures, const SDL_Rect& rect);
    void CleanTextures();

    std::vector<std::vector<int>> m_TileMap;
    std::vector<SDL_Texture*> m_Textures;
    int m_TileSize{};
    SDL_Rect m_DestRect;
    SDL_Rect m_SrcRect;
};


#endif //GOLFGAME_TILEMAP_H
