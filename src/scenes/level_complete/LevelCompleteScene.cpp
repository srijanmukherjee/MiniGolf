#include "LevelCompleteScene.h"
#include "../../engine/Game.h"
#include "../menu/MenuScene.h"
#include "../../GolfTileMap.h"
#include "../../res/Constant.h"

#include <SDL2/SDL_ttf.h>
#include <sstream>
#include <iomanip>

TTF_Font *FONT_MAIN;
SDL_Surface *surfaceLevelComplete;
SDL_Texture *textureLevelComplete;
SDL_Rect rectLevelComplete;

TTF_Font  *FONT_TIME_TOOK;
SDL_Surface *surfaceTimeTook;
SDL_Texture *textureTimeTook;
SDL_Rect rectTimeTook;

void LevelCompleteScene::Init() {
    Scene::Init();
    SDL_Color TEXT_COLOR{255, 255, 255, 255};
    FONT_MAIN = TTF_OpenFont("./assets/fonts/aAbstractGroovy.ttf", 52);
    FONT_TIME_TOOK = TTF_OpenFont("./assets/fonts/alarm clock.ttf", 72);

    if (FONT_MAIN == nullptr or FONT_TIME_TOOK == nullptr) {
        spdlog::error("failed to load font: {}", SDL_GetError());
    }

    int w, h;
    surfaceLevelComplete = TTF_RenderText_Solid(FONT_MAIN, "Game Complete", TEXT_COLOR);
    textureLevelComplete = SDL_CreateTextureFromSurface(Game::renderer, surfaceLevelComplete);
    TTF_SizeText(FONT_MAIN, "MiniGolf", &w, &h);
    rectLevelComplete = { Constant::SCREEN_WIDTH / 2 - w / 2, Constant::SCREEN_HEIGHT / 2 - h / 2 - 100, w + 10, h};

    // time took
    auto elapsedTime = static_cast<double>(m_TimeTookMillis); // Millis
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << elapsedTime / 1000.0;
    auto str = ss.str();
    surfaceTimeTook = TTF_RenderText_Solid(FONT_TIME_TOOK, str.c_str(), TEXT_COLOR);
    textureTimeTook = SDL_CreateTextureFromSurface(Game::renderer, surfaceTimeTook);
    TTF_SizeText(FONT_MAIN, str.c_str(), &w, &h);
    rectTimeTook = { Constant::SCREEN_WIDTH / 2 - w / 2, Constant::SCREEN_HEIGHT / 2 - h / 2, w + 10, h };

    m_Manager.AddEntity<GolfTileMap>(this);
}

void LevelCompleteScene::Draw() {
    Scene::Draw();

    SDL_Rect overlayRect{0, 0, Constant::SCREEN_WIDTH, Constant::SCREEN_HEIGHT};

    // overlay
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 150);
    SDL_RenderFillRect(Game::renderer, &overlayRect);

    SDL_RenderCopy(Game::renderer, textureLevelComplete, nullptr, &rectLevelComplete);
    SDL_RenderCopy(Game::renderer, textureTimeTook, nullptr, &rectTimeTook);
}

void LevelCompleteScene::Update(float deltaTime) {
    Scene::Update(deltaTime);
}

void LevelCompleteScene::HandleEvent(SDL_Event &event) {
    Scene::HandleEvent(event);

    switch (event.type) {
        case SDL_MOUSEBUTTONUP:
            Game::GetInstance().LoadScene(new MenuScene());
    }
}

LevelCompleteScene::~LevelCompleteScene() {
    SDL_FreeSurface(surfaceLevelComplete);
    SDL_DestroyTexture(textureLevelComplete);
    SDL_FreeSurface(surfaceTimeTook);
    SDL_DestroyTexture(textureTimeTook);
}
