#ifndef SDL_PLATFORMER_COMPONENT_H
#define SDL_PLATFORMER_COMPONENT_H

class Component {
public:
    virtual ~Component() {
    }

    virtual void Update(float deltaTime) {
    }

    class GameObject *owner;
};

#endif //SDL_PLATFORMER_COMPONENT_H
