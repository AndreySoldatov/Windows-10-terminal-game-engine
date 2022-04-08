//
// Created by Andrey on 06.08.2021.
//

#ifndef UNTITLED1_VEC2U_H
#define UNTITLED1_VEC2U_H

#include <iostream>

#include "Defines.h"
#include "Vec2i.h"

class Vec2i;

struct Vec2u {
    u32 x{};
    u32 y{};

    Vec2u();
    Vec2u(u32 x, u32 y);

    Vec2u operator+(Vec2u const &vec) const;
    Vec2u operator-(Vec2u const &vec) const;

    Vec2u operator*(i32 val) const;
    Vec2u operator/(i32 val) const;

    Vec2u operator+=(Vec2u const &vec);
    Vec2u operator-=(Vec2u const &vec);

    Vec2u operator*=(i32 val);
    Vec2u operator/=(i32 val);

    bool operator==(Vec2u const &vec) const;
    bool operator!=(Vec2u const &vec) const;

    [[nodiscard]] std::string to_string() const;
    Vec2i toVec2i() const;
};

std::ostream &operator<<(std::ostream &os, Vec2u const &vec);



#endif //UNTITLED1_VEC2U_H
