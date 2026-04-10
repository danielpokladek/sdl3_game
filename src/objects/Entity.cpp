#include <algorithm>

#include "Entity.h"

Entity::Entity(std::string name) : mName(std::move(name)) {
}

bool Entity::IsColliding(const Entity *other) const {
    SDL_FRect a = transform.GetRectangle();
    SDL_FRect b = other->transform.GetRectangle();

    return SDL_HasRectIntersectionFloat(&a, &b);
}

void Entity::Update(float deltaTime) {
    for (auto &component: mComponents) {
        component->Update(deltaTime);
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
