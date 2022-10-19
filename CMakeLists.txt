cmake_minimum_required(VERSION 3.0)
project(GolfGame)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(GolfGame
        src/res/Constant.h
        src/main.cpp
        src/engine/Game.h
        src/engine/Game.cpp
        src/engine/TextureManager.h
        src/engine/TextureManager.cpp
        src/math/Vector2D.h
        src/math/Vector2D.cpp
        src/engine/TileMap.h
        src/engine/TileMap.cpp
        src/GolfGame.h
        src/GolfGame.cpp
        src/GolfTileMap.h
        src/GolfTileMap.cpp
        src/math/Math.cpp
        src/math/Math.h
        src/engine/ECS/ECS.h
        src/engine/components/TransformComponent.h
        src/engine/components/SpriteComponent.h
        src/entity/Ball/BallEntity.cpp
        src/entity/Ball/BallEntity.h
        src/entity/Ball/DirectionComponent.h
        src/engine/components/Collider/ColliderComponent.h
        src/engine/components/Collider/Collision.cpp
        src/engine/components/Collider/Collision.h
        src/entity/CollidableEntity/CollidableEntity.h
        src/engine/components/Collider/CollisionManager.h
        src/engine/Scene.cpp
        src/engine/Scene.h
        src/scenes/play/PlayScene.cpp
        src/scenes/play/PlayScene.h
        src/entity/Wall/WallEntity.cpp src/entity/Wall/WallEntity.h src/engine/ECS/Manager.h src/entity/CollidableEntity/CollidableEntity.cpp src/entity/Obstacle/Obstacle.cpp src/entity/Obstacle/Obstacle.h src/entity/Obstacle/ObstacleSmall.h src/entity/Obstacle/ObstacleBig.h src/entity/Ball/PowerBarComponent.h src/entity/Goal/GoalEntity.cpp src/entity/Goal/GoalEntity.h src/scenes/menu/MenuScene.cpp src/scenes/menu/MenuScene.h src/res/Levels.h src/scenes/level_creator/LevelCreatorScene.cpp src/scenes/level_creator/LevelCreatorScene.h src/scenes/level_complete/LevelCompleteScene.cpp src/scenes/level_complete/LevelCompleteScene.h src/entity/Clock/ClockEntity.cpp src/entity/Clock/ClockEntity.h)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(GolfGame
        PUBLIC SDL2main SDL2 SDL2_image SDL2_ttf
        PRIVATE spdlog::spdlog)


