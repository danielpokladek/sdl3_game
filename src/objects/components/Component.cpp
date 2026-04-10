#include "Component.h"

#include "objects/Entity.h"

Component::Component(InputHandler *inputHandler) {
    mInputHandler = inputHandler;
}

void Component::SetOwner(Entity *owner) {
    mOwner = owner;
    mTransform = &owner->transform;
}
