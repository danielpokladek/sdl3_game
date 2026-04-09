#ifndef SDL_PLATFORMER_GAMEMANAGER_H
#define SDL_PLATFORMER_GAMEMANAGER_H
#include "Renderer.h"

class GameManager {
private:
    bool mIsInitialized = false;
    bool mIsRunning = false;

    Renderer *mRenderer = nullptr;

    uint64_t mPreviousTicks = 0;

public:
    GameManager();

    ~GameManager();

    bool HasInitialized() const { return mIsInitialized; }

    Renderer &GetRenderer() const { return *mRenderer; }

    void StartLoop();

    void Shutdown();
};

#endif //SDL_PLATFORMER_GAMEMANAGER_H
