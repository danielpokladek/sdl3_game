#include "GravityComponent.h"

GravityComponent::GravityComponent(InputHandler *inputHandler) : Component(inputHandler) {
    mVelocity = new glm::vec2(0, 0);
}

void GravityComponent::Update(float deltaTime) {
    if (mIsGrounded) {
        mVelocity->x = 0;
        mVelocity->y = 0;
    } else {
        mVelocity->y += 50.0f * deltaTime;
        mTransform->Position().x += mVelocity->x * deltaTime;
        mTransform->Position().y += mVelocity->y * deltaTime;
    }

    mIsGrounded = false;
}

void GravityComponent::SetVelocity(float x, float y) {
    mVelocity->x = x;
    mVelocity->y = y;
}

void GravityComponent::SetIsGrounded(bool isGrounded) {
    mIsGrounded = isGrounded;
}
