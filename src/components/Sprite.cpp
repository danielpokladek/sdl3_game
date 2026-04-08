#include "Sprite.h"

#include <iostream>
#include <ostream>

#include "../data/TileData.h"

Sprite::Sprite(std::string name) : GameObject(std::move(name)), mTileIndex(0) {
    mTexture = nullptr;
    mSpriteSize = new glm::vec2(SPRITESHEET_TILE_SIZE, SPRITESHEET_TILE_SIZE);
    mSpritePosition = new glm::vec2(0.0f, 0.0f);
}

void Sprite::SetTexture(SDL_Texture *newTexture, TileID tileIndex) {
    mTexture = newTexture;

    const int index = static_cast<int>(tileIndex);
    // mSpritePosition = new glm::vec2((index % SPRITESHEET_COLUMNS) * mSpriteSize->x,
    //                                 (index / SPRITESHEET_COLUMNS) * mSpriteSize->y);

    mSpritePosition->x = (index % SPRITESHEET_COLUMNS) * mSpriteSize->x;
    mSpritePosition->y = (index / SPRITESHEET_ROWS) * mSpriteSize->y;

    std::cout << index << std::endl;
    std::cout << mSpritePosition->x << std::endl;
    std::cout << mSpritePosition->y << std::endl;
}
