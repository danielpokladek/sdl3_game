#include "gameobject.h"

#include <algorithm>


GameObject::GameObject(std::string name) : position(0), scale(0) {
    mParent = nullptr;
    mName = name;
}

void GameObject::SetParent(GameObject *newParent) {
    mParent = newParent;
    // mParent->AddChild(this);
}

void GameObject::AddChild(GameObject *child) {
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

void GameObject::RemoveChild(GameObject *childToRemove) {
    return;
}
