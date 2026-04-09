#ifndef SDL_PLATFORMER_GAMEMANAGER_H
#define SDL_PLATFORMER_GAMEMANAGER_H
#include "InputHandler.h"
#include "Renderer.h"

class GameManager {
private:
    bool mIsInitialized = false;
    bool mIsRunning = false;

    Renderer *mRenderer = nullptr;
    InputHandler *mInputHandler = nullptr;

    uint64_t mPreviousTicks = 0;

public:
    GameManager();

    ~GameManager();

    bool HasInitialized() const { return mIsInitialized; }

    Renderer &GetRenderer() const { return *mRenderer; }

    InputHandler &GetInputHandler() const { return *mInputHandler; }

    void StartLoop();

    void Shutdown();
};

#endif //SDL_PLATFORMER_GAMEMANAGER_H
