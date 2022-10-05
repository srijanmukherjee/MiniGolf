#include "TextureManager.h"

#include "../res/Constant.h"

const std::string TextureManager::TEXTURE_PATH = Constant::ASSETS_DIR + "/textures/";

SDL_Texture *TextureManager::LoadTexture(const char *filename) {
    std::string path = TextureManager::TEXTURE_PATH + filename;
    SDL_Surface* surface = IMG_Load(path.c_str());

    if (surface == nullptr) {
        spdlog::error("Failed to load texture {}", path);
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect &srcRect, SDL_Rect &destRect) {
    if (SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect) < 0) {
        spdlog::warn("TextureManager::Draw rendering failed");
    }
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect &srcRect, SDL_Rect &destRect, const double angle,
                          const SDL_Point *center, const SDL_RendererFlip flip) {
    if (SDL_RenderCopyEx(Game::renderer, texture, &srcRect, &destRect, angle, center, flip) < 0) {
        spdlog::warn("TextureManager::Draw rendering failed");
    }
}
