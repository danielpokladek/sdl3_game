#ifndef SDL_PLATFORMER_COMPONENT_H
#define SDL_PLATFORMER_COMPONENT_H
#include "data/Transform.h"
#include "managers/InputHandler.h"

class Entity;

class Component {
protected:
    Transform *mTransform = nullptr;
    Entity *mOwner = nullptr;
    InputHandler *mInputHandler = nullptr;

public:
    Component(InputHandler *inputHandler);

    virtual ~Component() {
    }

    virtual void Update(float deltaTime) {
    }

    virtual void OnDrawDebug() {
    }

    void SetOwner(Entity *owner);
};

#endif //SDL_PLATFORMER_COMPONENT_H
