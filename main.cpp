#include <format>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <glm/glm.hpp>

#include "src/renderer.h"


int main() {
    auto *renderer = new Renderer();

    if (!renderer->Initialize()) {
        return 1;
    }

    uint64_t previousTime = SDL_GetTicks();
    bool isRunning = true;

    float test = 0;

    while (isRunning) {
        uint64_t currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - previousTime) / 1000.0f;

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

        SDL_SetRenderDrawColor(renderer->State().renderer, 34, 35, 35, 255);
        SDL_RenderClear(renderer->State().renderer);

        // Render stuff here...

        SDL_SetRenderDrawColor(renderer->State().renderer, 255, 255, 255, 255);
        SDL_RenderDebugText(renderer->State().renderer, 5, 5,
                            std::format("Test Value: {}", test).c_str());

        // Swap buffers and show the frame.
        SDL_RenderPresent(renderer->State().renderer);
        previousTime = currentTime;
    }

    renderer->Shutdown();

    return 0;
}
