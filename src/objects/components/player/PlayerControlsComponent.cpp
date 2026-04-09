#include "PlayerControlsComponent.h"

PlayerControlsComponent::PlayerControlsComponent(InputHandler *inputHandler) : Component(inputHandler) {
}

void PlayerControlsComponent::Update(float deltaTime) {
    if (mInputHandler->IsKeyDown(SDL_SCANCODE_A)) {
        mTransform->x -= 100.0f * deltaTime;
    }

    if (mInputHandler->IsKeyDown(SDL_SCANCODE_D)) {
        mTransform->x += 100.0f * deltaTime;
    }
}
