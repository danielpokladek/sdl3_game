#include "Component.h"

#include "objects/GameObject.h"

Component::Component(InputHandler *inputHandler) {
    mInputHandler = inputHandler;
}

void Component::SetOwner(GameObject *owner) {
    mOwner = owner;
    mTransform = &owner->transform;
}
