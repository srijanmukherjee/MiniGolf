#include "TileMap.h"

TileMap::TileMap(void *scene) : Entity(scene) {
}

TileMap::~TileMap() {
    spdlog::info("cleaning up tile map");
    CleanTextures();
}

void TileMap::Draw() {
    m_DestRect.x = m_DestRect.y = 0;

    for (int row = 0; row < m_TileMap.size(); row++) {
        for (int col = 0; col < m_TileMap[row].size(); col++) {
            m_DestRect.x = col * m_TileSize;
            m_DestRect.y = row * m_TileSize;
            TextureManager::Draw(m_Textures[m_TileMap[row][col]], m_SrcRect, m_DestRect);
        }
    }

    Entity::Draw();
}

void TileMap::LoadMap(const std::vector<std::vector<int>> &map, int tileSize) {
    spdlog::info("TileMap::LoadMap");
    m_TileSize = tileSize;
    m_DestRect.w = m_DestRect.h = tileSize;
    m_TileMap = map;
    spdlog::info("TileMap::LoadMap loaded map of dimension {}x{}", map.size(), map[0].size());
}

void TileMap::LoadTextures(const std::vector<const char *>& textures, const SDL_Rect& rect) {
    spdlog::info("Loading textures");
    m_SrcRect = rect;
    CleanTextures();
    for (auto textureFileName : textures) {
        m_Textures.push_back(TextureManager::LoadTexture(textureFileName));
    }
}

void TileMap::CleanTextures() {
    for (auto & m_Texture : m_Textures) {
        SDL_DestroyTexture(m_Texture);
    }
    m_Textures.clear();
}
