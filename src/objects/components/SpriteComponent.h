#ifndef SDL_PLATFORMER_SPRITE_H
#define SDL_PLATFORMER_SPRITE_H

#include <glm/vec2.hpp>
#include <SDL3/SDL.h>

#include "Component.h"

class SpriteComponent : public Component {
private:
    SDL_Renderer *mRenderer;
    SDL_Texture *mTexture;

    int mTileIndex;

    glm::vec2 *mSpriteSize;
    glm::vec2 *mSpritePosition;

public:
    SpriteComponent(SDL_Renderer *renderer, SDL_Texture *texture = nullptr, int tileIndex = 0);

    ~SpriteComponent();

    glm::vec2 *GetSpriteSize() const { return mSpriteSize; }
    glm::vec2 *GetSpritePosition() const { return mSpritePosition; }

    SDL_Texture *GetTexture() const { return mTexture; }

    void SetTexture(SDL_Texture *newTexture, int tileIndex = 0);

    void Update(float deltaTime) override;
};

#endif //SDL_PLATFORMER_SPRITE_H
