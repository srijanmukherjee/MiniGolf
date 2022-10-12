#include <sstream>
#include "LevelCreatorScene.h"
#include "../../entity/Obstacle/ObstacleSmall.h"
#include "../../entity/Obstacle/ObstacleBig.h"

void LevelCreatorScene::Init() {
    Scene::Init();
    Game::GetInstance().SetWindowTitle("Level Creator");
    m_Manager.AddEntity<GolfTileMap>(this);
}

void LevelCreatorScene::HandleEvent(SDL_Event &event) {
    Scene::HandleEvent(event);

    switch(event.type) {
        case SDL_MOUSEBUTTONUP:
            PlaceComponent();
            break;

        case SDL_KEYUP:
            ChangeComponent(event.key);
            if (event.key.keysym.sym == 'e') Export();
            break;
    }
}

void LevelCreatorScene::PlaceComponent() {
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    int x = mx / 32, y = my / 32;
    if (x < 0 || y < 0) return;

    int w;
    Obstacle* obstacle;

    switch (m_SelectedComponent) {
        case GameComponent::BALL:
            if (m_BallEntity != nullptr) {
                m_BallEntity->Destroy();
                m_Manager.Refresh();
            }

            m_BallEntity = &m_Manager.AddEntity<BallEntity>(this);
            w = m_BallEntity->GetComponent<TransformComponent>().width;
            m_BallEntity->GetComponent<TransformComponent>().position = Vector2D(x * 32 + w / 2, y * 32 + w / 2);
            break;

        case GameComponent::GOAL:
            if (m_GoalEntity != nullptr) {
                m_GoalEntity->Destroy();
                m_Manager.Refresh();
            }

            m_GoalEntity = &m_Manager.AddEntity<GoalEntity>(this, y, x);
            break;

        case GameComponent::OBSTACLE_LG:
            if (m_ObstaclesBig[{x, y}] != nullptr) {
                m_ObstaclesBig[{x, y}]->Destroy();
                m_Manager.Refresh();
            }

            obstacle = &m_Manager.AddEntity<ObstacleBig>(this);
            obstacle->SetPosition(x * 32, y * 32);
            m_ObstaclesBig[{x, y}] = obstacle;
            break;

        case GameComponent::OBSTACLE_SM:
            if (m_ObstaclesSmall[{x, y}] != nullptr) {
                m_ObstaclesSmall[{x, y}]->Destroy();
                m_Manager.Refresh();
            }

            obstacle = &m_Manager.AddEntity<ObstacleSmall>(this);
            obstacle->SetPosition(x * 32, y * 32);
            m_ObstaclesSmall[{x, y}] = obstacle;
            break;
    }

}

void LevelCreatorScene::ChangeComponent(const SDL_KeyboardEvent &key) {
    spdlog::info("pressed {} key", key.keysym.sym);

    switch(key.keysym.sym) {
        case 'b':
            m_SelectedComponent = GameComponent::BALL;
            break;

        case 'g':
            m_SelectedComponent = GameComponent::GOAL;
            break;

        case 's':
            m_SelectedComponent = GameComponent::OBSTACLE_SM;
            break;

        case 'l':
            m_SelectedComponent = GameComponent::OBSTACLE_LG;
            break;
    }
}

void LevelCreatorScene::Export() {
    if (m_BallEntity == nullptr) {
        spdlog::error("ExportError: Ball is not initialised");
        return;
    }

    if (m_GoalEntity == nullptr) {
        spdlog::error("ExportError: Goal is not initialised");
        return;
    }

    std::stringstream ss;
    ss << "{";

    // small obstacles
    ss << "{";
    int i = 0;
    for (auto posObstacle : m_ObstaclesSmall) {
        if (i++ > 0) ss << ", ";
        ss << "{" << posObstacle.first.first << ", " << posObstacle.first.second << "}";
    }
    ss << "}, ";


    // big obstacles
    ss << "{";
    i = 0;
    for (auto posObstacle : m_ObstaclesBig) {
        if (i++ > 0) ss << ", ";
        ss << "{" << posObstacle.first.first << ", " << posObstacle.first.second << "}";
    }
    ss << "}, ";

    // goal pos
    auto& goalTransform = m_GoalEntity->GetComponent<TransformComponent>();
    ss << "{" << static_cast<int>(goalTransform.position.x / 32) << ", " << static_cast<int>(goalTransform.position.y / 32) << "}, ";

    auto& ballTransform = m_BallEntity->GetComponent<TransformComponent>();
    ss << "{" << static_cast<int>(ballTransform.position.x / 32) << ", " << static_cast<int>(ballTransform.position.y / 32) << "}";

    ss << "}";

    spdlog::info(ss.str());
}
