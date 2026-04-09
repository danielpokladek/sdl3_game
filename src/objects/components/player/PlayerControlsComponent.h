#ifndef SDL_PLATFORMER_PLAYERCONTROLSCOMPONENT_H
#define SDL_PLATFORMER_PLAYERCONTROLSCOMPONENT_H

#include "../Component.h"

class PlayerControlsComponent : public Component {
public:
    PlayerControlsComponent(InputHandler *inputHandler);

    void Update(float deltaTime) override;
};

#endif //SDL_PLATFORMER_PLAYERCONTROLSCOMPONENT_H
