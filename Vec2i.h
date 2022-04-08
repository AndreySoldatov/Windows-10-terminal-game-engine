//
// Created by Andrey on 06.08.2021.
//

#ifndef UNTITLED1_VEC2I_H
#define UNTITLED1_VEC2I_H

#include <iostream>
#include <cmath>

#include "Defines.h"
#include "Vec2u.h"

class Vec2u;

struct Vec2i {
    i32 x;
    i32 y;

    Vec2i();
    Vec2i(i32 x, i32 y);

    Vec2i operator+(Vec2i const &vec) const;
    Vec2i operator-(Vec2i const &vec) const;

    Vec2i operator*(i32 val) const;
    Vec2i operator/(i32 val) const;

    Vec2i operator+=(Vec2i const &vec);
    Vec2i operator-=(Vec2i const &vec);

    Vec2i operator*=(i32 val);
    Vec2i operator/=(i32 val);

    bool operator==(Vec2i const &vec);

    [[nodiscard]] std::string to_string() const;
    Vec2u toVec2u() const;

    float length() const;
};

std::ostream &operator<<(std::ostream &os, Vec2i const &vec);

#endif //UNTITLED1_VEC2I_H
