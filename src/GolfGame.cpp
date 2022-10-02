#include "GolfGame.h"
#include "GolfTileMap.h"

GolfTileMap *tileMap;

void GolfGame::Init(const char *title, int x, int y, int width, int height, bool fullscreen) {
    Game::Init(title, x, y, width, height, fullscreen);
    tileMap = new GolfTileMap();
};

void GolfGame::Update() {

}

void GolfGame::HandleEvents() {
    Game::HandleEvents();
}

void GolfGame::RenderGame() {
    tileMap->RenderMap();
}

GolfGame::~GolfGame() {
    delete tileMap;
}