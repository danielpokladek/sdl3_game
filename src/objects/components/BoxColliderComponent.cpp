#include "BoxColliderComponent.h"

#include <iostream>
#include <ostream>

#include "objects/Entity.h"

BoxColliderComponent::BoxColliderComponent(InputHandler *inputHandler,
                                           SDL_Renderer *renderer) : Component(inputHandler),
                                                                     mRenderer(renderer) {
    mColliderRect = new SDL_FRect();
}

SDL_FRect BoxColliderComponent::GetColliderRect() const {
    auto &position = mTransform->Position();

    return {
        .x = position.x + mColliderRect->x,
        .y = position.y + mColliderRect->y,
        .w = mColliderRect->w,
        .h = mColliderRect->h
    };
}

bool BoxColliderComponent::IsColliding(const BoxColliderComponent *other) const {
    SDL_FRect a = GetColliderRect();
    SDL_FRect b = other->GetColliderRect();

    return SDL_HasRectIntersectionFloat(&a, &b);
}

void BoxColliderComponent::OnDrawDebug() {
    SDL_FRect colliderRect = GetColliderRect();

    SDL_SetRenderDrawColor(mRenderer, 0, 255, 0, 255);
    SDL_RenderRect(mRenderer, &colliderRect);
}

void BoxColliderComponent::SetSize(const float width, const float height) {
    mColliderRect->w = width;
    mColliderRect->h = height == HUGE_VAL ? width : height;
}
