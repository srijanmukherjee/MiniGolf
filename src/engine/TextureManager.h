#ifndef GOLFGAME_TEXTUREMANAGER_H
#define GOLFGAME_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static const std::string TEXTURE_PATH;
    static SDL_Texture* LoadTexture(const char *filename);
    static void Draw(SDL_Texture* texture, SDL_Rect& srcRect, SDL_Rect& destRect);
    static void Draw(SDL_Texture* texture, SDL_Rect& srcRect, SDL_Rect& destRect, const double angle, const SDL_Point *center = NULL, const SDL_RendererFlip flip = SDL_FLIP_NONE);
};


#endif //GOLFGAME_TEXTUREMANAGER_H
