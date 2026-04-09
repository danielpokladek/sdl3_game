#include <algorithm>

#include "GameObject.h"

GameObject::GameObject(std::string name) : mName(std::move(name)) {
}

void GameObject::Update(float deltaTime) {
    for (auto &component: mComponents) {
        component->Update(deltaTime);
    }
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
