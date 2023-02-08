cmake_minimum_required(VERSION 3.24)
project(NGUEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

add_executable(NGUEngine src/main.cpp src/game.cpp src/game.h src/constants.h)
target_link_libraries(NGUEngine ${SDL2_LIBRARIES})

