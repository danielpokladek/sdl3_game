#ifndef SDL_PLATFORMER_BOXCOLLIDERCOMPONENT_H
#define SDL_PLATFORMER_BOXCOLLIDERCOMPONENT_H

#include <math.h>
#include <SDL3/SDL_render.h>

#include "Component.h"

class BoxColliderComponent : public Component {
private:
    SDL_Renderer *mRenderer = nullptr;

    SDL_FRect *mColliderRect;

public:
    BoxColliderComponent(InputHandler *inputHandler, SDL_Renderer *renderer);

    [[nodiscard]] bool IsColliding(const BoxColliderComponent *other) const;

    [[nodiscard]] SDL_FRect GetColliderRect() const;

    void OnDrawDebug() override;

    void SetSize(float width, float height = HUGE_VAL);
};

#endif //SDL_PLATFORMER_BOXCOLLIDERCOMPONENT_H
