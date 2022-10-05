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
        src/engine/TileMap.h
        src/engine/TileMap.cpp
        src/GolfGame.h
        src/GolfGame.cpp
        src/GolfTileMap.h
        src/GolfTileMap.cpp src/math/Math.cpp src/math/Math.h src/engine/ECS/ECS.h src/engine/components/TransformComponent.h src/engine/components/SpriteComponent.h src/entitiy/Ball/BallEntity.cpp src/entitiy/Ball/BallEntity.h src/entitiy/Ball/DirectionComponent.h src/engine/components/Collider/ColliderComponent.h src/engine/components/Collider/Collision.cpp src/engine/components/Collider/Collision.h src/entitiy/CollidableEntity/CollidableEntity.h src/engine/components/Collider/CollisionManager.h src/engine/Scene.cpp src/engine/Scene.h src/scenes/play/PlayScene.cpp src/scenes/play/PlayScene.h src/res/Constant.h src/entitiy/Wall/WallEntity.cpp src/entitiy/Wall/WallEntity.h src/engine/ECS/Manager.h src/entitiy/CollidableEntity/CollidableEntity.cpp src/entitiy/Obstacle/Obstacle.cpp src/entitiy/Obstacle/Obstacle.h src/entitiy/Obstacle/ObstacleSmall.h src/entitiy/Obstacle/ObstacleBig.h src/entitiy/Ball/PowerBarComponent.h)

target_link_libraries(GolfGame
        PUBLIC SDL2main SDL2 SDL2_image
        PRIVATE spdlog::spdlog)


