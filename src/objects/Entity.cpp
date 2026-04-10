#include <algorithm>

#include "Entity.h"

Entity::Entity(std::string name) : mName(std::move(name)) {
    transform = new Transform();
}

Entity::~Entity() {
    transform = nullptr;
}

const std::vector<Entity *> &Entity::GetChildren() const {
    return mChildren;
}

std::string Entity::Name() const {
    return mName;
}

void Entity::Update(float deltaTime) {
    for (auto &component: mComponents) {
        component->Update(deltaTime);
        component->OnDrawDebug();
    }
}

void Entity::AddChild(Entity *child) {
    if (child->mParent != nullptr) {
        child->mParent->RemoveChild(child);
    }

    child->mParent = this;
    mChildren.push_back(child);
}

void Entity::RemoveChild(Entity *child) {
    auto it = std::remove(mChildren.begin(), mChildren.end(), child);

    if (it != mChildren.end()) {
        mChildren.erase(it);
        child->mParent = nullptr;
    }
}
