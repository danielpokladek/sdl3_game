#ifndef SDL_PLATFORMER_SPRITE_H
#define SDL_PLATFORMER_SPRITE_H

#include <SDL3/SDL.h>

#include "GameObject.h"
#include "../data/TileData.h"

class Sprite : public GameObject {
private:
    SDL_Texture *mTexture;

    int mTileIndex;

    glm::vec2 *mSpriteSize;
    glm::vec2 *mSpritePosition;

public:
    Sprite(std::string name = "Sprite");

    glm::vec2 *GetSpriteSize() const { return mSpriteSize; }
    glm::vec2 *GetSpritePosition() const { return mSpritePosition; }

    SDL_Texture *GetTexture() const { return mTexture; }

    void SetTexture(SDL_Texture *newTexture, TileID tileIndex);
};

#endif //SDL_PLATFORMER_SPRITE_H
