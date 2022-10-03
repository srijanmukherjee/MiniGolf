//
// Created by srijan on 10/2/22.
//

#include "Math.h"

namespace GameMath {
    double Map(double value, double currLo, double currHi, double newLo, double newHi) {
        return (value - currLo) / (currHi - currLo) * (newHi - newLo) + newLo;
    }
} // GameMath