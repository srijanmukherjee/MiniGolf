//
// Created by srijan on 10/2/22.
//

#ifndef GOLFGAME_VECTOR2D_H
#define GOLFGAME_VECTOR2D_H

#include <cmath>

namespace GameMath {

    class Vector2D {
    public:
        Vector2D() = default;
        Vector2D(int x, int y);
        double Magnitude() const;
        Vector2D Add(const Vector2D& other);
        Vector2D Subtract(const Vector2D& other);

        Vector2D operator+(const Vector2D& other);
        Vector2D operator-(const Vector2D& other);
        void operator+=(const Vector2D& other);
        void operator-=(const Vector2D& other);

    public:
        int x{0};
        int y{0};
    };

} // GameMath

#endif //GOLFGAME_VECTOR2D_H
