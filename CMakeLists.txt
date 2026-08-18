cmake_minimum_required(VERSION 3.14)

project(CLIENT C)

# Фикс переменной стандарта C
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)

FetchContent_MakeAvailable(raylib)

add_executable(CLIENT WIN32 src/main.c src/Visualflare/grid.c src/PhysicStuff/ball.c)

target_include_directories(CLIENT PRIVATE include)

target_link_libraries(CLIENT PRIVATE raylib)