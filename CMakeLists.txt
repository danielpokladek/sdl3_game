cmake_minimum_required(VERSION 4.2)
project(sdl3_game)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(glm REQUIRED)

add_executable(sdl3_game main.cpp
        src/renderer.cpp
        src/renderer.h)

# Include SDL3 in the project.
target_include_directories(sdl3_game PUBLIC ${SDL3_INCLUDE_DIRS})

# Link SDL3 core libraries.
target_link_libraries(sdl3_game PRIVATE SDL3::SDL3 SDL3_image::SDL3_image glm::glm)