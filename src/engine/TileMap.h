#ifndef GOLFGAME_TILEMAP_H
#define GOLFGAME_TILEMAP_H

#include <vector>

#include "Game.h"
#include "GameObject.h"

class TileMap : public GameObject {
public:
    TileMap() = default;
    ~TileMap();

    void Render() override;
protected:
    void LoadMap(const std::vector<std::vector<int>> &map, int tileSize);
    void LoadTextures(const std::vector<const char *> &textures, const SDL_Rect &rect);
    void CleanTextures();

    std::vector<std::vector<int>> m_TileMap;
    std::vector<SDL_Texture *> m_Textures;
    int m_TileSize{};
};


#endif //GOLFGAME_TILEMAP_H
