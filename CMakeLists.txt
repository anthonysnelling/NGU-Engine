cmake_minimum_required(VERSION 3.24)
project(NGUEngine)

#set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
#    set(SDL2_INCLUDE_DIR C:/libs/SDL2/include )
#    set(SDL2_LIB_DIR C:/libs/SDL2/lib/x64 )

    set(SDL2_INCLUDE_DIR C:/libs/SDL2_MINGW/i686-w64-mingw32/include/SDL2 )
    set(SDL2_LIB_DIR C:/libs/SDL2/lib/x64 )

    set(SDL2_IMAGE_INCLUDE_DIR C:/libs/SDL2_Image/i686-w64-mingw32/include/SDL2 )
    set(SDL2_IMAGE_LIB_DIR C:/libs/SDL2_MINGW/i686-w64-mingw32/lib )

    set(SDL2_TTF_INCLUDE_DIR C:/libs/SDL2_TTF/i686-w64-mingw32/include/SDL2)
    set(SDL2_TTF_LIB_DIR C:/libs/SDL2_TTF/i686-w64-mingw32/lib)

#    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
    link_directories(${SDL2_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_TTF_LIB_DIR})

    add_executable(NGUEngine src/main.cpp src/game.cpp src/game.h src/constants.h)
    target_link_libraries(NGUEngine SDL2main  SDL2 )
endif (WIN32)

if (UNIX)
    find_package(SDL2 REQUIRED)

    add_executable(NGUEngine src/main.cpp src/game.cpp src/game.h src/constants.h)
    target_link_libraries(NGUEngine ${SDL2_LIBRARIES})
endif (UNIX)


