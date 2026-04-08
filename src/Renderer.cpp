#include "Renderer.h"

Renderer::Renderer() : rendererData() {
}

Renderer::~Renderer() = default;

bool Renderer::Initialize() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Unable to initialize SDL!", nullptr);
        return false;
    }

    rendererData.window = SDL_CreateWindow("SDL3", rendererData.windowWidth, rendererData.windowHeight,
                                           SDL_WINDOW_RESIZABLE);

    if (!rendererData.window) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Unable to create window!", nullptr);
        Shutdown();

        return false;
    }

    rendererData.renderer = SDL_CreateRenderer(rendererData.window, nullptr);

    if (!rendererData.renderer) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Unable to create renderer!", nullptr);
        Shutdown();

        return false;
    }

    SDL_SetRenderLogicalPresentation(rendererData.renderer, rendererData.logicalWidth, rendererData.logicalHeight,
                                     SDL_LOGICAL_PRESENTATION_LETTERBOX);

    return true;
}

void Renderer::Shutdown() const {
    SDL_DestroyRenderer(rendererData.renderer);
    SDL_DestroyWindow(rendererData.window);
    SDL_Quit();
}

void Renderer::SetWindowSize(const int width, const int height) {
    rendererData.windowWidth = width;
    rendererData.windowHeight = height;
}

void Renderer::SetRendererSize(const int width, const int height) {
    rendererData.logicalWidth = width;
    rendererData.logicalHeight = height;
}

void Renderer::DrawObject(Sprite *sprite) {
    auto spriteSize = sprite->GetSpriteSize();
    auto spritePosition = sprite->GetSpritePosition();

    SDL_FRect src{
        .x = spritePosition->x,
        .y = spritePosition->y,
        .w = spriteSize->x,
        .h = spriteSize->y
    };

    SDL_FRect dest{
        .x = sprite->position.x, .y = sprite->position.y,
        .w = spriteSize->x, .h = spriteSize->y
    };

    SDL_RenderTextureRotated(State().renderer, sprite->GetTexture(), &src, &dest, 0, nullptr,
                             SDL_FLIP_NONE);
}
