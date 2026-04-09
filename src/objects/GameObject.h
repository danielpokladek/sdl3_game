#ifndef SDL_PLATFORMER_GAMEOBJECT_H
#define SDL_PLATFORMER_GAMEOBJECT_H

#include <memory>
#include <vector>

#include "components/Component.h"
#include "data/Transform.h"

class GameObject {
private:
    std::string mName;

    GameObject *mParent = nullptr;
    std::vector<GameObject *> mChildren;

    std::vector<std::unique_ptr<Component> > mComponents;

public:
    Transform transform = {
        0, 0, 0, 0, 1, 1
    };

public:
    GameObject(std::string name = "GameObject");

    virtual ~GameObject() = default;

    const std::vector<GameObject *> &GetChildren() const { return mChildren; }

    void Update(float deltaTime);

    template<typename T, typename... TArgs>
    T &AddComponent(TArgs &&... args) {
        T *component(new T(std::forward<TArgs>(args)...));
        component->SetOwner(this);

        std::unique_ptr<Component> uPtr{component};
        mComponents.emplace_back(std::move(uPtr));
        return *component;
    }

    template<typename T>
    T *GetComponent() const {
        for (auto &component: mComponents) {
            T *target = dynamic_cast<T *>(component);

            if (target != nullptr) {
                return target;
            }
        }

        return nullptr;
    }

    void AddChild(GameObject *child);

    void RemoveChild(GameObject *child);
};

#endif //SDL_PLATFORMER_GAMEOBJECT_H
