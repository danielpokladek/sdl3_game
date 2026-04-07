#ifndef SDL_PLATFORMER_RENDERER_H
#define SDL_PLATFORMER_RENDERER_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <glm/glm.hpp>

struct RendererData {
    SDL_Window *window;
    SDL_Renderer *renderer;

    int windowWidth;
    int windowHeight;
    int logicalWidth;
    int logicalHeight;

    RendererData() {
        window = nullptr;
        renderer = nullptr;

        windowWidth = 1600;
        windowHeight = 900;
        logicalWidth = 640;
        logicalHeight = 320;
    }
};

class Renderer {
private:
    RendererData rendererData;

public:
    Renderer();

    ~Renderer();

    bool Initialize();

    void Shutdown() const;

    void SetWindowSize(int width, int height);

    void SetRendererSize(int width, int height);

    RendererData &State() { return rendererData; }
};

#endif
