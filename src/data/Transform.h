#ifndef SDL_PLATFORMER_TRANSFORM_H
#define SDL_PLATFORMER_TRANSFORM_H
#include <glm/vec2.hpp>
#include <SDL3/SDL_rect.h>

class Transform {
private:
    glm::vec2 mPosition;
    glm::vec2 mSize;
    glm::vec2 mScale;

    float mRotation = 0;

public:
    Transform() : mPosition(0), mSize(0), mScale(1) {
    }

    [[nodiscard]] glm::vec2 &Position() {
        return mPosition;
    }

    void SetPosition(const float x, const float y) {
        mPosition.x = x;
        mPosition.y = y;
    }

    void SetPosition(const glm::vec2 position) {
        mPosition.x = position.x;
        mPosition.y = position.y;
    }

    [[nodiscard]] glm::vec2 Size() const {
        return mSize;
    }

    void SetSize(const float x, const float y) {
        mSize.x = x;
        mSize.y = y;
    }

    void SetSize(const glm::vec2 size) {
        mSize.x = size.x;
        mSize.y = size.y;
    }

    [[nodiscard]] glm::vec2 Scale() const {
        return mScale;
    }

    void SetScale(const float x, const float y) {
        mScale.x = x;
        mScale.y = y;
    }

    void SetScale(const glm::vec2 scale) {
        mScale.x = scale.x;
        mScale.y = scale.y;
    }

    [[nodiscard]] SDL_FRect GetRectangle() const {
        return {mPosition.x, mPosition.y, mSize.x, mSize.y};
    }
};


#endif //SDL_PLATFORMER_TRANSFORM_H
