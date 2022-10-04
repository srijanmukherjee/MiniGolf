#include <iostream>
#include "Vector2D.h"

namespace GameMath {
    Vector2D::Vector2D(float x, float y): x(x), y(y)
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

    Vector2D Vector2D::operator*(float val) const {
        return {x * val, y * val};
    }

    Vector2D Vector2D::operator/(float val) const {
        return {x / val, y / val};
    }

    void Vector2D::operator*=(float val) {
        x *= val;
        y *= val;
    }

    void Vector2D::operator/=(float val) {
        x /= val;
        y /= val;
    }

    float Vector2D::Magnitude() const {
        return std::sqrt(Magnitude2());
    }

    float Vector2D::Magnitude2() const {
        return x * x + y * y;
    }

    float Vector2D::dist(const Vector2D &other) const {
        return (*this - other).Magnitude();
    }

    float Vector2D::dist2(const Vector2D &other) const {
        return (*this - other).Magnitude2();
    }

    Vector2D Vector2D::UnitVector() const {
        return *this / Magnitude();
    }

    std::ostream &operator<<(std::ostream &stream, const Vector2D &vec) {
        stream << "Vector2D(x: " << vec.x << ", y: " << vec.y << ")";
        return stream;
    }

    bool Vector2D::operator==(const Vector2D &other) const {
        return x == other.x && y == other.y;
    }

    float Vector2D::Dot(const Vector2D &other) const {
        return x * other.x + y * other.y;
    }

    [[maybe_unused]] float Vector2D::angleBetween(const Vector2D &other) const {
        return std::acos(Dot(other) / (Magnitude() * other.Magnitude()));
    }
} // GameMath