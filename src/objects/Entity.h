#ifndef SDL_PLATFORMER_GAMEOBJECT_H
#define SDL_PLATFORMER_GAMEOBJECT_H

#include <memory>
#include <vector>

#include "components/Component.h"
#include "data/Transform.h"

class Entity {
private:
    std::string mName;

    Entity *mParent = nullptr;
    std::vector<Entity *> mChildren;

    std::vector<std::unique_ptr<Component> > mComponents;

public:
    Transform *transform = nullptr;

public:
    Entity(std::string name = "GameObject");

    virtual ~Entity();

    [[nodiscard]] const std::vector<Entity *> &GetChildren() const;

    [[nodiscard]] std::string Name() const;

    [[nodiscard]] bool IsColliding(const Entity *other) const;

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
    T *GetComponent() {
        for (auto &component: mComponents) {
            if (T *target = dynamic_cast<T *>(component.get())) {
                return target;
            }
        }

        return nullptr;
    }

    template<typename T>
    const T *GetComponent() const {
        for (auto &component: mComponents) {
            if (T *target = dynamic_cast<T *>(component.get())) {
                return target;
            }
        }

        return nullptr;
    }

    void AddChild(Entity *child);

    void RemoveChild(Entity *child);
};

#endif //SDL_PLATFORMER_GAMEOBJECT_H
