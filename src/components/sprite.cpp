#include "sprite.h"

Sprite::Sprite(std::string name) : GameObject(std::move(name)), mSpriteSize(16) {
    mTexture = nullptr;
}

void Sprite::SetTexture(SDL_Texture *newTexture) {
    mTexture = newTexture;
}
