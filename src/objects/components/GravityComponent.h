#ifndef SDL_PLATFORMER_GRAVITYCOMPONENT_H
#define SDL_PLATFORMER_GRAVITYCOMPONENT_H
#include <glm/glm.hpp>

#include "Component.h"

class GravityComponent : public Component {
private:
    glm::vec2 *mVelocity;

public:
    GravityComponent(InputHandler *inputHandler);

    glm::vec2 &GetVelocity() const { return *mVelocity; }

    void Update(float deltaTime) override;

    void SetVelocity(float x, float y);
};

#endif //SDL_PLATFORMER_GRAVITYCOMPONENT_H
