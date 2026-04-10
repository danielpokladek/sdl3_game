#include "App.h"

#include <format>
#include <string>
#include <SDL3_image/SDL_image.h>

#include "data/TileData.h"
#include "objects/Entity.h"
#include "objects/components/BoxColliderComponent.h"
#include "objects/components/GravityComponent.h"
#include "objects/components/player/PlayerControlsComponent.h"

App::App() {
    auto *renderer = new Renderer();

    if (!renderer->Initialize()) {
        renderer->Shutdown();
        return;
    }

    auto *inputHandler = new InputHandler();
    mInputHandler = inputHandler;

    mRenderer = renderer;
    mPreviousTicks = SDL_GetTicks();

    mIsRunning = true;
    mIsInitialized = true;
}

App::~App() = default;

void App::StartLoop() {
    SDL_Renderer *sdlRenderer = mRenderer->Data().renderer;

    std::string spritesheetPath = "assets/sprites/kenney/spritesheet.png";

    SDL_Texture *spritesheet = IMG_LoadTexture(sdlRenderer, spritesheetPath.c_str());
    SDL_SetTextureScaleMode(spritesheet, SDL_SCALEMODE_NEAREST);

    auto *container = new Entity();

    for (int i = 0; i < 5; i++) {
        const bool isFirst = i == 0;
        const bool isLast = i == 4;
        const TileID tile = isFirst
                                ? TileID::GroundSecondaryLeft
                                : isLast
                                      ? TileID::GroundSecondaryRight
                                      : TileID::GroundSecondaryCenter;

        auto *tileGO = new Entity();
        tileGO->transform->Position().x = 50 + i * 16;
        tileGO->transform->Position().y = 300;
        container->AddChild(tileGO);

        tileGO->AddComponent<SpriteComponent>(mInputHandler, sdlRenderer, spritesheet,
                                              static_cast<int>(tile));
    }

    auto *player = new Entity();
    player->transform->Position().x = 60;
    player->transform->Position().y = 250;
    auto collider = player->AddComponent<BoxColliderComponent>(mInputHandler, sdlRenderer);
    collider.SetSize(SPRITESHEET_TILE_SIZE);
    // player->AddComponent<GravityComponent>(mInputHandler);
    player->AddComponent<SpriteComponent>(mInputHandler, sdlRenderer, spritesheet,
                                          static_cast<int>(TileID::PlayerIdle));
    player->AddComponent<PlayerControlsComponent>(mInputHandler);
    container->AddChild(player);

    float test = 0.0f;

    while (mIsRunning) {
        const uint64_t currentTicks = SDL_GetTicks();
        const float deltaTime = (currentTicks - mPreviousTicks) / 1000.0f;

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

                case SDL_EVENT_KEY_DOWN:
                case SDL_EVENT_KEY_UP: {
                    mInputHandler->HandleEvent(event);
                    break;
                }

                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(sdlRenderer, 34, 35, 35, 255);
        SDL_RenderClear(sdlRenderer);

        // Render stuff here...
        for (auto &child: container->GetChildren()) {
            child->Update(deltaTime);
        }

        // TODO: For now just showing elapsed time.
        SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
        SDL_RenderDebugText(sdlRenderer, 5, 5,
                            std::format("Test Value: {}", test).c_str());

        // Swap buffers and show the frame.
        SDL_RenderPresent(sdlRenderer);
        mPreviousTicks = currentTicks;
    }
}

void App::Shutdown() {
    mRenderer->Shutdown();
}
