#ifndef GOLFGAME_LEVELS_H
#define GOLFGAME_LEVELS_H

#include <vector>
#include "Constant.h"

namespace {
    const int ROWS = Constant::SCREEN_HEIGHT / 32;
    const int COLS = Constant::SCREEN_WIDTH / 32;
}

struct LevelDescriptor {
    std::vector<std::pair<int, int>> smObstacles;
    std::vector<std::pair<int, int>> lgObstacles;
    std::pair<int, int> goalPos;
    std::pair<int, int> ballPos;
};

const LevelDescriptor levels[] = {
        {
            { { 10, 8 }, {11, 8}, {12, 8}, {13, 8}, {14, 8} },
         {{13, 14}, {10, 14}, {10, 12}, {13, 12}},
         {COLS / 2, ROWS / 2}, {COLS/2, ROWS - 1}}
};

#endif //GOLFGAME_LEVELS_H
