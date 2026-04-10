#include "SpriteComponent.h"

#include "data/TileData.h"
#include "objects/Entity.h"

SpriteComponent::SpriteComponent(InputHandler *inputHandler, SDL_Renderer *renderer, SDL_Texture *texture,
                                 int tileIndex) : Component(inputHandler) {
    mRenderer = renderer;
    mTexture = texture;
    mTileIndex = tileIndex;
    mSpriteSize = new glm::vec2(SPRITESHEET_TILE_SIZE, SPRITESHEET_TILE_SIZE);
    mSpritePosition = new glm::vec2(0.0f, 0.0f);

    if (mTexture != nullptr) {
        SetTexture(mTexture, mTileIndex);
    }
}

SpriteComponent::~SpriteComponent() = default;

void SpriteComponent::SetTexture(SDL_Texture *newTexture, const int tileIndex) {
    mTexture = newTexture;
    mTileIndex = tileIndex;

    mSpritePosition->x = (tileIndex % SPRITESHEET_COLUMNS) * mSpriteSize->x;
    mSpritePosition->y = (tileIndex / SPRITESHEET_ROWS) * mSpriteSize->y;
}

void SpriteComponent::Update(float deltaTime) {
    SDL_FRect src{
        .x = mSpritePosition->x,
        .y = mSpritePosition->y,
        .w = mSpriteSize->x,
        .h = mSpriteSize->y
    };

    SDL_FRect dest{
        .x = mTransform->Position().x,
        .y = mTransform->Position().y,
        .w = mSpriteSize->x,
        .h = mSpriteSize->y
    };

    SDL_RenderTextureRotated(mRenderer, mTexture, &src, &dest, mTransform->Rotation(), nullptr,
                             SDL_FLIP_NONE);
}
