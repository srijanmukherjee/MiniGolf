//
// Created by srijan on 10/2/22.
//

#include <iostream>
#include "Vector2D.h"

namespace GameMath {
    Vector2D::Vector2D(double x, double y): x(x), y(y)
    { }

    Vector2D::Vector2D(int x, int y): x(x), y(y)
    { }

    Vector2D Vector2D::Add(const Vector2D &other) const {
        return {x + other.x, y + other.y};
    }

    Vector2D Vector2D::Subtract(const Vector2D &other) const {
        return {x - other.x, y - other.y};
    }

    Vector2D Vector2D::operator+(const Vector2D &other) const {
        return this->Add(other);
    }

    Vector2D Vector2D::operator-(const Vector2D &other) const {
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

    Vector2D Vector2D::operator*(double val) const {
        return {x * val, y * val};
    }

    Vector2D Vector2D::operator/(double val) const {
        return {x / val, y / val};
    }

    void Vector2D::operator*=(double val) {
        x *= val;
        y *= val;
    }

    double Vector2D::Magnitude() const {
        return std::sqrt(Magnitude2());
    }

    double Vector2D::Magnitude2() const {
        return x * x + y * y;
    }

    double Vector2D::dist(const Vector2D &other) const {
        return (*this - other).Magnitude();
    }

    double Vector2D::dist2(const Vector2D &other) const {
        return (*this - other).Magnitude2();
    }

    Vector2D Vector2D::UnitVector() const {
        return *this / (int) Magnitude();
    }
} // GameMath