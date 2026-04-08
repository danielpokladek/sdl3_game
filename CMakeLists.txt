cmake_minimum_required(VERSION 4.2)
project(sdl_platformer)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(glm REQUIRED)

add_executable(sdl_platformer main.cpp
        src/renderer.cpp
        src/renderer.h
        src/components/gameobject.cpp
        src/components/gameobject.h
        src/components/sprite.cpp
        src/components/sprite.h
        src/data/spritesheet.cpp
        src/data/spritesheet.h)

# Include SDL3 in the project.
target_include_directories(sdl_platformer PUBLIC ${SDL3_INCLUDE_DIRS})

# Link SDL3 core libraries.
target_link_libraries(sdl_platformer PRIVATE SDL3::SDL3 SDL3_image::SDL3_image glm::glm)