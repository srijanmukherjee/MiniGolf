//
// Created by srijan on 10/2/22.
//

#ifndef GOLFGAME_TEXTUREMANAGER_H
#define GOLFGAME_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char *filename);
    static void Draw(SDL_Texture* texture, SDL_Rect& srcRect, SDL_Rect& destRect);
};


#endif //GOLFGAME_TEXTUREMANAGER_H
