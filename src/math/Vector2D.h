//
// Created by srijan on 10/2/22.
//

#ifndef GOLFGAME_VECTOR2D_H
#define GOLFGAME_VECTOR2D_H

#include <cmath>

namespace GameMath {

    struct Vector2D {
        Vector2D() = default;
        Vector2D(float x, float y);
        Vector2D(int x, int y);
        [[nodiscard]] float Magnitude() const;
        [[nodiscard]] float Magnitude2() const;
        [[nodiscard]] float dist(const Vector2D& other) const;
        [[nodiscard]] float dist2(const Vector2D& other) const;
        [[nodiscard]] Vector2D Add(const Vector2D& other) const;
        [[nodiscard]] Vector2D Subtract(const Vector2D& other) const;
        [[nodiscard]] Vector2D UnitVector() const;
        [[nodiscard]] float Dot(const Vector2D& other) const;
        [[maybe_unused]] [[nodiscard]] float angleBetween(const Vector2D& other) const;

        Vector2D operator+(const Vector2D& other) const;
        Vector2D operator-(const Vector2D& other) const;
        Vector2D operator/(float val) const;
        Vector2D operator*(float val) const;
        void operator*=(float val);
        void operator/=(float val);
        void operator+=(const Vector2D& other);
        void operator-=(const Vector2D& other);
        bool operator==(const Vector2D& other) const;

        friend std::ostream& operator<<(std::ostream& stream, const Vector2D &vect);

        float x{};
        float y{0};
    };

} // GameMath

#endif //GOLFGAME_VECTOR2D_H
