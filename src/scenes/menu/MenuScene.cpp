#include "MenuScene.h"
#include "../../GolfTileMap.h"
#include "../../res/Constant.h"
#include "../play/PlayScene.h"
#include "SDL2/SDL_ttf.h"

GolfTileMap *tileMap2;
TTF_Font *FONT_TITLE;
TTF_Font *FONT_HINT;
SDL_Color TEXT_COLOR{255, 255, 255};

SDL_Surface *surfaceTitle;
SDL_Texture *textureTitle;
SDL_Rect rectTitle;

SDL_Surface *surfaceHint;
SDL_Texture *textureHint;
SDL_Rect rectHint;

void MenuScene::Init() {
    Scene::Init();
    tileMap2 = new GolfTileMap();
    FONT_TITLE = TTF_OpenFont("./assets/fonts/Warrior of World 400.ttf", 78);
    FONT_HINT = TTF_OpenFont("./assets/fonts/Honey Mints 400.ttf", 32);

    if (FONT_TITLE == nullptr || FONT_HINT == nullptr) {
        spdlog::error("failed to load font: {}", SDL_GetError());
    }

    int w, h;
    surfaceTitle = TTF_RenderText_Solid(FONT_TITLE, "MiniGolf", TEXT_COLOR);
    textureTitle = SDL_CreateTextureFromSurface(Game::renderer, surfaceTitle);
    TTF_SizeText(FONT_TITLE, "MiniGolf", &w, &h);
    rectTitle = { Constant::SCREEN_WIDTH / 2 - w / 2, Constant::SCREEN_HEIGHT / 2 - h / 2 - 100, w, h};

    surfaceHint = TTF_RenderText_Solid(FONT_HINT, "Click to start playing", TEXT_COLOR);
    textureHint = SDL_CreateTextureFromSurface(Game::renderer, surfaceHint);
    TTF_SizeText(FONT_HINT, "Click to start playing", &w, &h);
    rectHint = { Constant::SCREEN_WIDTH / 2 - w / 2, Constant::SCREEN_HEIGHT / 2 - h / 2 + 90, w, h };
}

void MenuScene::Update(float deltaTime) {
    Scene::Update(deltaTime);
}

void MenuScene::HandleEvent(SDL_Event &event) {
    Scene::HandleEvent(event);

    switch(event.type) {
        case SDL_MOUSEBUTTONUP:
            Game::GetInstance().LoadScene(new PlayScene());
            break;
    }
}

void MenuScene::Draw() {
    SDL_Rect rect{0, 0, Constant::SCREEN_WIDTH, Constant::SCREEN_HEIGHT};
    tileMap2->Render();

    // overlay
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 150);
    SDL_RenderFillRect(Game::renderer, &rect);

    // texts
    SDL_RenderCopy(Game::renderer, textureTitle, nullptr, &rectTitle);
    SDL_RenderCopy(Game::renderer, textureHint, nullptr, &rectHint);

    Scene::Draw();
}

MenuScene::~MenuScene() {
    SDL_FreeSurface(surfaceTitle);
    SDL_DestroyTexture(textureTitle);
    SDL_FreeSurface(surfaceHint);
    SDL_DestroyTexture(textureHint);
}
