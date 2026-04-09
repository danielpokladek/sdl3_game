#include "Component.h"

#include "objects/GameObject.h"

void Component::SetOwner(GameObject *owner) {
    mOwner = owner;
    mTransform = &owner->transform;
}
