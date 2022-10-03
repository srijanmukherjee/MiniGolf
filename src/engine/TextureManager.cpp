//
// Created by srijan on 10/2/22.
//

#include "TextureManager.h"

SDL_Texture *TextureManager::LoadTexture(const char *filename) {
    SDL_Surface* surface = IMG_Load(filename);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect &srcRect, SDL_Rect &destRect) {
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect &srcRect, SDL_Rect &destRect, const double angle,
                          const SDL_Point *center, const SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Game::renderer, texture, &srcRect, &destRect, angle, center, flip);
}
