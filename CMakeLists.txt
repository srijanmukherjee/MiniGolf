cmake_minimum_required(VERSION 3.0)
project(GolfGame)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(GolfGame
        src/main.cpp
        src/engine/Game.h
        src/engine/Game.cpp
        src/engine/GameObject.h
        src/engine/GameObject.cpp
        src/engine/TextureManager.h
        src/engine/TextureManager.cpp
        src/math/Vector2D.h
        src/math/Vector2D.cpp
        src/GolfBallGameObject.h
        src/GolfBallGameObject.cpp
        src/engine/TileMap.h
        src/engine/TileMap.cpp
        src/GolfGame.h
        src/GolfGame.cpp
        src/GolfTileMap.h
        src/GolfTileMap.cpp src/math/Math.cpp src/math/Math.h)

target_link_libraries(GolfGame
        PUBLIC SDL2main SDL2 SDL2_image
        PRIVATE spdlog::spdlog)


