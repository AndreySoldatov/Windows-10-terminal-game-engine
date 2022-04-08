//
// Created by Andrey on 08.08.2021.
//

#include "Color.h"

Color::Color(unsigned short r, unsigned short g, unsigned short b) : r(r), g(g), b(b) {}

std::string Color::toEscFormat() const {
    return std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b);
}

Color::Color(u8 v) : r(v), g(v), b(v) {}

Color Color::blend(Color c, std::function<float(float, float)> const &f) const {
    return Color(
            static_cast<int>(f((static_cast<float>(r) / 256.0), (static_cast<float>(c.r) / 256.0)) * 256.0),
            static_cast<int>(f((static_cast<float>(g) / 256.0), (static_cast<float>(c.g) / 256.0)) * 256.0),
            static_cast<int>(f((static_cast<float>(b) / 256.0), (static_cast<float>(c.b) / 256.0)) * 256.0)
            );
}

Color Color::lerp(Color const &color, float val) {
    return Color(
            interpolation(r, color.r, val),
            interpolation(g, color.g, val),
            interpolation(b, color.b, val));
}

std::string Color::to_string() {
    return
    std::string() +
    "(" +
    std::to_string(r) +
    ", " +
    std::to_string(g) +
    ", " +
    std::to_string(b) +
    ")";
}

float Color::brightness() {
    return static_cast<float>(static_cast<u32>(r) + g + b) / 768.0f;
}

u8 interpolation(u8 v1, u8 v2, float val) {
    return static_cast<u8>(static_cast<float>(static_cast<i32>(v2) - static_cast<i32>(v1)) * val) + v1;
}

std::ostream &operator<<(std::ostream &os, Color c) {
    os << c.to_string();
    return os;
}