#ifndef SDL_PLATFORMER_SPRITE_H
#define SDL_PLATFORMER_SPRITE_H
#include "gameobject.h"
#include <SDL3/SDL.h>

class Sprite : public GameObject {
private:
    SDL_Texture *mTexture;

    glm::vec2 *mSpriteSize;
    glm::vec2 *mSpritePosition;

public:
    Sprite(std::string name = "Sprite");

    glm::vec2 *GetSpriteSize() const { return mSpriteSize; }
    glm::vec2 *GetSpritePosition() const { return mSpritePosition; }

    SDL_Texture *GetTexture() const { return mTexture; }

    void SetTexture(SDL_Texture *newTexture, glm::vec2 *spriteSize, glm::vec2 *spritePosition);
};

#endif //SDL_PLATFORMER_SPRITE_H
