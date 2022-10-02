//
// Created by srijan on 10/2/22.
//

#include "Vector2D.h"

namespace GameMath {
    Vector2D::Vector2D(int x, int y): x(x), y(y)
    { }

    Vector2D Vector2D::Add(const Vector2D &other) {
        return {x + other.x, y + other.y};
    }

    Vector2D Vector2D::Subtract(const Vector2D &other) {
        return {x - other.x, y - other.y};
    }

    Vector2D Vector2D::operator+(const Vector2D &other) {
        return this->Add(other);
    }

    Vector2D Vector2D::operator-(const Vector2D &other) {
        return this->Subtract(other);
    }

    void Vector2D::operator+=(const Vector2D &other) {
        x += other.x;
        y += other.y;
    }

    void Vector2D::operator-=(const Vector2D &other) {
        x -= other.x;
        y -= other.y;
    }

    double Vector2D::Magnitude() const {
        return std::sqrt(x * x + y * y);
    }
} // GameMath