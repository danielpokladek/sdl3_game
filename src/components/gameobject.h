#ifndef SDL_PLATFORMER_GAMEOBJECT_H
#define SDL_PLATFORMER_GAMEOBJECT_H
#include <memory>
#include <vector>
#include <glm/vec2.hpp>

class GameObject {
private:
    std::string mName;

    GameObject *mParent;
    std::vector<GameObject *> mChildren;

public:
    glm::vec2 position;
    glm::vec2 scale;

public:
    GameObject(std::string name = "GameObject");

    virtual ~GameObject() = default;

    const std::vector<GameObject *> &GetChildren() const { return mChildren; }

    void SetParent(GameObject *newParent);

    void AddChild(GameObject *child);

    void RemoveChild(GameObject *child);
};

#endif //SDL_PLATFORMER_GAMEOBJECT_H
