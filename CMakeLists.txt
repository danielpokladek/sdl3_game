cmake_minimum_required(VERSION 4.2)
project(sdl_platformer)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(glm REQUIRED)

add_executable(sdl_platformer main.cpp
        src/Renderer.cpp
        src/Renderer.h
        src/objects/Entity.cpp
        src/objects/Entity.h
        src/objects/components/SpriteComponent.cpp
        src/objects/components/SpriteComponent.h
        src/data/TileData.h
        src/objects/components/Component.h
        src/managers/App.cpp
        src/managers/App.h
        src/objects/components/player/PlayerControlsComponent.h
        src/objects/components/player/PlayerControlsComponent.cpp
        src/objects/components/Component.cpp
        src/data/Transform.h
        src/managers/InputHandler.cpp
        src/managers/InputHandler.h
        src/objects/components/GravityComponent.cpp
        src/objects/components/GravityComponent.h
        src/objects/components/BoxColliderComponent.cpp
        src/objects/components/BoxColliderComponent.h
)

# Include SDL3 in the project.
target_include_directories(sdl_platformer PUBLIC ${SDL3_INCLUDE_DIRS} PRIVATE src)

# Link SDL3 core libraries.
target_link_libraries(sdl_platformer PRIVATE SDL3::SDL3 SDL3_image::SDL3_image glm::glm)