#ifndef SDL_PLATFORMER_SPRITE_H
#define SDL_PLATFORMER_SPRITE_H
#include "gameobject.h"
#include <SDL3/SDL.h>

class Sprite : public GameObject {
private:
    SDL_Texture *mTexture;
    glm::vec2 mSpriteSize;

public:
    Sprite(std::string name = "Sprite");

    SDL_Texture *GetTexture() const { return mTexture; }
    glm::vec2 GetSpriteSize() const { return mSpriteSize; }

    void SetTexture(SDL_Texture *newTexture);
};

#endif //SDL_PLATFORMER_SPRITE_H
