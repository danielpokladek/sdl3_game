#ifndef SDL_PLATFORMER_TRANSFORM_H
#define SDL_PLATFORMER_TRANSFORM_H
#include <SDL3/SDL_rect.h>

struct Transform {
    float x, y;
    float w, h;
    float scaleX, scaleY;

    SDL_FRect GetRectangle() const { return {x, y, w, h}; }
};


#endif //SDL_PLATFORMER_TRANSFORM_H
