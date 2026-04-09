#include <filesystem>
#include <format>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

#include "Renderer.h"
#include "data/TileData.h"
#include "objects/GameObject.h"
#include "objects/components/SpriteComponent.h"

int main() {
    auto *renderer = new Renderer();

    if (!renderer->Initialize()) {
        return 1;
    }

    uint64_t previousTime = SDL_GetTicks();
    bool isRunning = true;

    float test = 0;

    std::string spritesheetPath = "assets/sprites/kenney/spritesheet.png";

    SDL_Texture *spritesheet = IMG_LoadTexture(renderer->Data().renderer, spritesheetPath.c_str());
    SDL_SetTextureScaleMode(spritesheet, SDL_SCALEMODE_NEAREST);

    auto *container = new GameObject();

    const int offsetX = 50;
    const int offsetY = 300;

    for (int i = 0; i < 5; i++) {
        bool isFirst = i == 0;
        bool isLast = i == 4;
        TileID tile = isFirst ? TileID::GroundLeft : isLast ? TileID::GroundRight : TileID::GroundCenter;

        auto *tileGO = new GameObject();
        tileGO->transform.x = offsetX + i * 16;
        tileGO->transform.y = offsetY;
        container->AddChild(tileGO);

        tileGO->AddComponent<SpriteComponent>(renderer->Data().renderer, spritesheet,
                                              static_cast<int>(tile));
    }

    while (isRunning) {
        const uint64_t currentTime = SDL_GetTicks();
        const float deltaTime = static_cast<float>(currentTime - previousTime) / 1000.0f;

        test += deltaTime;
        SDL_Event event{0};

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: {
                    isRunning = false;
                    break;
                }

                case SDL_EVENT_WINDOW_RESIZED: {
                    renderer->SetWindowSize(event.window.data1, event.window.data2);
                    break;
                }

                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer->Data().renderer, 34, 35, 35, 255);
        SDL_RenderClear(renderer->Data().renderer);

        // Render stuff here...
        for (auto &child: container->GetChildren()) {
            child->Update(deltaTime);
        }

        // TODO: For now just showing elapsed time.
        SDL_SetRenderDrawColor(renderer->Data().renderer, 255, 255, 255, 255);
        SDL_RenderDebugText(renderer->Data().renderer, 5, 5,
                            std::format("Test Value: {}", test).c_str());

        // Swap buffers and show the frame.
        SDL_RenderPresent(renderer->Data().renderer);
        previousTime = currentTime;
    }

    renderer->Shutdown();

    return 0;
}


