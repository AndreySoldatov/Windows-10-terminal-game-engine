//
// Created by Andrey on 08.08.2021.
//

#ifndef UNTITLED1_COLOR_H
#define UNTITLED1_COLOR_H

#include <string>
#include <functional>

#include "Defines.h"

struct Color {
    u8 r{};
    u8 g{};
    u8 b{};

public:
    Color() = default;
    Color(u8 r, u8 g, u8 b);
    explicit Color(u8 v);

    [[nodiscard]] std::string toEscFormat() const;
    Color blend(Color c, std::function<float(float, float)> const &f) const;
    Color lerp(Color const &color, float val);
    std::string to_string();
    float brightness();
};

std::ostream &operator<<(std::ostream &os, Color c);

u8 interpolation(u8 v1, u8 v2, float val);

#endif //UNTITLED1_COLOR_H
