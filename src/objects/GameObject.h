#ifndef SDL_PLATFORMER_GAMEOBJECT_H
#define SDL_PLATFORMER_GAMEOBJECT_H

#include <memory>
#include <vector>
#include <glm/vec2.hpp>

#include "components/Component.h"

class GameObject {
private:
    std::string mName;

    GameObject *mParent;
    std::vector<GameObject *> mChildren;

    std::vector<std::unique_ptr<Component> > mComponents;

public:
    glm::vec2 position;
    glm::vec2 scale;

public:
    GameObject(std::string name = "GameObject");

    virtual ~GameObject() = default;

    const std::vector<GameObject *> &GetChildren() const { return mChildren; }

    void Update(float deltaTime);

    template<typename T, typename... TArgs>
    T &AddComponent(TArgs &&... args) {
        T *component(new T(std::forward<TArgs>(args)...));
        component->owner = this;

        std::unique_ptr<Component> uPtr{component};
        mComponents.emplace_back(std::move(uPtr));
        return *component;
    }

    void AddChild(GameObject *child);

    void RemoveChild(GameObject *child);
};

#endif //SDL_PLATFORMER_GAMEOBJECT_H
