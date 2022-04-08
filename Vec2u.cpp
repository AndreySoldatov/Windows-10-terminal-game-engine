//
// Created by Andrey on 06.08.2021.
//

#include "Vec2u.h"

Vec2u::Vec2u() : x(), y() {}

Vec2u::Vec2u(u32 x, u32 y) : x(x), y(y) {}

Vec2u Vec2u::operator+(Vec2u const &vec) const {
    return Vec2u(x + vec.x, y + vec.y);
}

Vec2u Vec2u::operator-(Vec2u const &vec) const {
    return Vec2u(
            (x >= vec.x) ? x - vec.x : 0,
            (y >= vec.y) ? y - vec.y : 0);
}

Vec2u Vec2u::operator*(i32 val) const {
    return Vec2u(x * val, y * val);
}

Vec2u Vec2u::operator/(i32 val) const {
    if(val != 0)
        return Vec2u(x / val, y / val);
    return Vec2u(U32_MAX, U32_MAX);
}

Vec2u Vec2u::operator+=(Vec2u const &vec) {
    x += vec.x;
    y += vec.y;
    return Vec2u(*this);
}

Vec2u Vec2u::operator-=(Vec2u const &vec) {
    x -= vec.x;
    y -= vec.y;
    return Vec2u(*this);
}

Vec2u Vec2u::operator*=(i32 val) {
    x *= val;
    y *= val;
    return Vec2u(*this);
}

Vec2u Vec2u::operator/=(i32 val) {
    if(val != 0) {
        x /= val;
        y /= val;
    }
    return Vec2u(*this);
}

bool Vec2u::operator==(Vec2u const &vec) const {
    return (x == vec.x && y == vec.y);
}

bool Vec2u::operator!=(Vec2u const &vec) const {
    return !(*this==vec);
}

std::string Vec2u::to_string() const {
    return std::string("(") + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vec2i Vec2u::toVec2i() const {
    return Vec2i(static_cast<i32>(x), static_cast<i32>(y));
}

std::ostream &operator<<(std::ostream &os, Vec2u const &vec) {
    return os << vec.to_string();
}
