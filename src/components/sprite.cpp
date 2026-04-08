#include "sprite.h"

Sprite::Sprite(std::string name) : GameObject(std::move(name)) {
    mTexture = nullptr;
    mSpriteSize = new glm::vec2(0.0f, 0.0f);
    mSpritePosition = new glm::vec2(0.0f, 0.0f);
}

void Sprite::SetTexture(SDL_Texture *newTexture, glm::vec2 *spriteSize, glm::vec2 *spritePosition) {
    mTexture = newTexture;
    mSpriteSize = spriteSize;
    mSpritePosition = spritePosition;
}
