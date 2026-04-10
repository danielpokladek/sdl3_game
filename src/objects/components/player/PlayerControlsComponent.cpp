#include "PlayerControlsComponent.h"

PlayerControlsComponent::PlayerControlsComponent(InputHandler *inputHandler) : Component(inputHandler) {
}

void PlayerControlsComponent::Update(float deltaTime) {
    if (mInputHandler->IsKeyDown(SDL_SCANCODE_A)) {
        mTransform->Position().x -= 100.0f * deltaTime;
    }

    if (mInputHandler->IsKeyDown(SDL_SCANCODE_D)) {
        mTransform->Position().x += 100.0f * deltaTime;
    }
}
