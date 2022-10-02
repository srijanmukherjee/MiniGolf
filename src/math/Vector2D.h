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
        Vector2D(double x, double y);
        Vector2D(int x, int y);
        [[nodiscard]] double Magnitude() const;
        [[nodiscard]] double Magnitude2() const;
        [[nodiscard]] double dist(const Vector2D& other) const;
        [[nodiscard]] double dist2(const Vector2D& other) const;
        [[nodiscard]] Vector2D Add(const Vector2D& other) const;
        [[nodiscard]] Vector2D Subtract(const Vector2D& other) const;
        [[nodiscard]] Vector2D UnitVector() const;

        Vector2D operator+(const Vector2D& other) const;
        Vector2D operator-(const Vector2D& other) const;
        Vector2D operator/(double val) const;
        Vector2D operator*(double val) const;
        void operator*=(double val);
        void operator+=(const Vector2D& other);
        void operator-=(const Vector2D& other);

    public:
        double x{0};
        double y{0};
    };

} // GameMath

#endif //GOLFGAME_VECTOR2D_H
