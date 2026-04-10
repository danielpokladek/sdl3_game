#include "GravityComponent.h"

GravityComponent::GravityComponent(InputHandler *mInputHandler) : Component(mInputHandler) {
    mVelocity = new glm::vec2(0, 0);
}

void GravityComponent::Update(float deltaTime) {
    mVelocity->y += 50.0f * deltaTime;
    mTransform->Position().x += mVelocity->x * deltaTime;
    mTransform->Position().y += mVelocity->y * deltaTime;
}

void GravityComponent::SetVelocity(float x, float y) {
    mVelocity->x = x;
    mVelocity->y = y;
}
