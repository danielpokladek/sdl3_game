#include "GameManager.h"

#include <format>
#include <string>
#include <SDL3_image/SDL_image.h>

#include "data/TileData.h"
#include "objects/GameObject.h"
#include "objects/components/player/PlayerControlsComponent.h"

GameManager::GameManager() {
    auto *renderer = new Renderer();

    if (!renderer->Initialize()) {
        renderer->Shutdown();
        return;
    }

    mRenderer = renderer;
    mPreviousTicks = SDL_GetTicks();

    mIsRunning = true;
    mIsInitialized = true;
}

void GameManager::StartLoop() {
    SDL_Renderer *renderer = mRenderer->Data().renderer;

    std::string spritesheetPath = "assets/sprites/kenney/spritesheet.png";

    SDL_Texture *spritesheet = IMG_LoadTexture(renderer, spritesheetPath.c_str());
    SDL_SetTextureScaleMode(spritesheet, SDL_SCALEMODE_NEAREST);

    auto *container = new GameObject();

    for (int i = 0; i < 5; i++) {
        const bool isFirst = i == 0;
        const bool isLast = i == 4;
        const TileID tile = isFirst ? TileID::GroundLeft : isLast ? TileID::GroundRight : TileID::GroundCenter;

        auto *tileGO = new GameObject();
        tileGO->transform.x = 50 + i * 16;
        tileGO->transform.y = 300;
        container->AddChild(tileGO);

        tileGO->AddComponent<SpriteComponent>(renderer, spritesheet,
                                              static_cast<int>(tile));
    }

    auto *player = new GameObject();
    player->transform.x = 60;
    player->transform.y = 250;
    player->AddComponent<SpriteComponent>(renderer, spritesheet,
                                          static_cast<int>(TileID::PlayerIdle));
    player->AddComponent<PlayerControlsComponent>();
    container->AddChild(player);

    float test = 0.0f;

    while (mIsRunning) {
        const uint64_t currentTicks = SDL_GetTicks();
        const float deltaTime = static_cast<float>(currentTicks - mPreviousTicks) / 1000.0f;

        test += deltaTime;
        SDL_Event event{0};

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: {
                    mIsRunning = false;
                    break;
                }

                case SDL_EVENT_WINDOW_RESIZED: {
                    mRenderer->SetWindowSize(event.window.data1, event.window.data2);
                    break;
                }

                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 34, 35, 35, 255);
        SDL_RenderClear(renderer);

        // Render stuff here...
        for (auto &child: container->GetChildren()) {
            child->Update(deltaTime);
        }

        // TODO: For now just showing elapsed time.
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDebugText(renderer, 5, 5,
                            std::format("Test Value: {}", test).c_str());

        // Swap buffers and show the frame.
        SDL_RenderPresent(renderer);
        mPreviousTicks = currentTicks;
    }
}

void GameManager::Shutdown() {
    mRenderer->Shutdown();
}
