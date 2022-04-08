//
// Created by Andrey on 06.08.2021.
//

#include "Vec2i.h"

Vec2i::Vec2i() : x(), y() {}

Vec2i::Vec2i(i32 x, i32 y) : x(x), y(y) {}

Vec2i Vec2i::operator+(Vec2i const &vec) const {
    return Vec2i(x + vec.x, y + vec.y);
}

Vec2i Vec2i::operator-(Vec2i const &vec) const {
    return Vec2i(x - vec.x, y - vec.y);
}

Vec2i Vec2i::operator*(i32 val) const {
    return Vec2i(x * val, y * val);
}

Vec2i Vec2i::operator/(i32 val) const {
    return Vec2i(x / val, y / val);
}

Vec2i Vec2i::operator+=(Vec2i const &vec) {
    x += vec.x;
    y += vec.y;
    return Vec2i(*this);
}

Vec2i Vec2i::operator-=(Vec2i const &vec) {
    x -= vec.x;
    y -= vec.y;
    return Vec2i(*this);
}

Vec2i Vec2i::operator*=(i32 val) {
    x *= val;
    y *= val;
    return Vec2i(*this);
}

Vec2i Vec2i::operator/=(i32 val) {
    if(val != 0) {
        x /= val;
        y /= val;
    }
    return Vec2i(*this);
}

bool Vec2i::operator==(Vec2i const &vec) {
    return (x == vec.x && y == vec.y);
}

std::string Vec2i::to_string() const {
    return std::string("(") + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vec2u Vec2i::toVec2u() const {
    return Vec2u((x >= 0) ? x : 0, (y >= 0) ? y : 0);
}

float Vec2i::length() const {
    return std::sqrt(static_cast<float>(x * x + y * y));
}

std::ostream &operator<<(std::ostream &os, Vec2i const &vec) {
    return os << vec.to_string();
}
