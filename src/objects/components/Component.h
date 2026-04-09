#ifndef SDL_PLATFORMER_COMPONENT_H
#define SDL_PLATFORMER_COMPONENT_H
#include "data/Transform.h"
#include "managers/InputHandler.h"

class GameObject;

class Component {
protected:
    Transform *mTransform = nullptr;
    GameObject *mOwner = nullptr;
    InputHandler *mInputHandler = nullptr;

public:
    Component(InputHandler *inputHandler);

    virtual ~Component() {
    }

    virtual void Update(float deltaTime) {
    }

    void SetOwner(GameObject *owner);
};

#endif //SDL_PLATFORMER_COMPONENT_H
