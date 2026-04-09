#ifndef SDL_PLATFORMER_COMPONENT_H
#define SDL_PLATFORMER_COMPONENT_H
#include "data/Transform.h"

class GameObject;

class Component {
protected:
    Transform *mTransform = nullptr;
    GameObject *mOwner = nullptr;

public:
    virtual ~Component() {
    }

    virtual void Update(float deltaTime) {
    }

    void SetOwner(GameObject *owner);
};

#endif //SDL_PLATFORMER_COMPONENT_H
