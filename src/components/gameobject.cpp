#include <algorithm>

#include "gameobject.h"

GameObject::GameObject(std::string name) : position(0), scale(0) {
    mParent = nullptr;
    mName = name;
}

void GameObject::AddChild(GameObject *child) {
    if (child->mParent != nullptr) {
        child->mParent->RemoveChild(child);
    }

    child->mParent = this;
    mChildren.push_back(child);
}

void GameObject::RemoveChild(GameObject *child) {
    auto it = std::remove(mChildren.begin(), mChildren.end(), child);

    if (it != mChildren.end()) {
        mChildren.erase(it);
        child->mParent = nullptr;
    }
}
