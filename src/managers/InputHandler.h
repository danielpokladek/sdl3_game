#ifndef SDL_PLATFORMER_INPUTHANDLER_H
#define SDL_PLATFORMER_INPUTHANDLER_H

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_scancode.h>

class InputHandler {
private:
    bool mKeyStates[SDL_SCANCODE_COUNT] = {false};

    SDL_Scancode mLastKeyDown = SDL_SCANCODE_UNKNOWN;
    SDL_Scancode mLastKeyUp = SDL_SCANCODE_UNKNOWN;

    float mMouseX = 0;
    float mMouseY = 0;

public:
    void HandleEvent(SDL_Event event);

    void ResetLastKeys();

    bool IsKeyDown(SDL_Scancode key);

    bool WasPressedThisFrame(SDL_Scancode key);

    bool WasReleasedThisFrame(SDL_Scancode key);
};

#endif //SDL_PLATFORMER_INPUTHANDLER_H
