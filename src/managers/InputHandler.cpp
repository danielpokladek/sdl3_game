#include "InputHandler.h"

void InputHandler::HandleEvent(SDL_Event event) {
    SDL_GetMouseState(&mMouseX, &mMouseY);

    SDL_Scancode code = event.key.scancode;

    if (code == SDL_SCANCODE_UNKNOWN) return;

    if (event.type == SDL_EVENT_KEY_DOWN) {
        mKeyStates[code] = true;
        mLastKeyDown = code;
    } else {
        mKeyStates[code] = false;
        mLastKeyUp = code;
    }
}

void InputHandler::ResetLastKeys() {
    mLastKeyDown = SDL_SCANCODE_UNKNOWN;
    mLastKeyUp = SDL_SCANCODE_UNKNOWN;
}

bool InputHandler::IsKeyDown(SDL_Scancode key) {
    return mKeyStates[key];
}

bool InputHandler::WasPressedThisFrame(SDL_Scancode key) {
    return mLastKeyDown == key;
}

bool InputHandler::WasReleasedThisFrame(SDL_Scancode key) {
    return mLastKeyUp == key;
}
