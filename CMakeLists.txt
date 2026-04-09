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
        src/objects/GameObject.cpp
        src/objects/GameObject.h
        src/objects/components/SpriteComponent.cpp
        src/objects/components/SpriteComponent.h
        src/data/TileData.h
        src/objects/components/Component.h
        src/objects/components/PlayerControlsComponent.cpp
        src/objects/components/PlayerControlsComponent.h
        src/managers/GameManager.cpp
        src/managers/GameManager.h
)

# Include SDL3 in the project.
target_include_directories(sdl_platformer PUBLIC ${SDL3_INCLUDE_DIRS} PRIVATE src)

# Link SDL3 core libraries.
target_link_libraries(sdl_platformer PRIVATE SDL3::SDL3 SDL3_image::SDL3_image glm::glm)