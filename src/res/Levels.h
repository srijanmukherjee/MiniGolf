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
         {COLS / 2, ROWS / 2}, {COLS/2, ROWS - 1}},
        {{{0, 2}, {0, 3}, {0, 4}, {2, 0}, {3, 0}, {3, 7}, {4, 0}, {4, 4}, {4, 7}, {5, 5}, {5, 7}, {6, 6}, {6, 7}, {7, 3}, {7, 4}, {7, 5}, {7, 6}, {7, 7}}, {{0, 6}, {2, 2}, {6, 0}}, {0, 0}, {24, 19}}
};

#endif //GOLFGAME_LEVELS_H
