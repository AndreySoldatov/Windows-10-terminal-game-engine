//
// Created by Andrey on 06.08.2021.
//

#ifndef UNTITLED1_POINT_H
#define UNTITLED1_POINT_H

#include <iostream>

#include "Vec2i.h"
#include "Color.h"

struct Point {
    Vec2i pos;
    char ch;
    Color color;

    Point();
    Point(i32 x, i32 y, char c, Color col);
    Point(Vec2i pos_, char c, Color col);

    [[nodiscard]] const Vec2i &getPos() const;
    void setPos(const Vec2i &pos);
    [[nodiscard]] char getCh() const;
    void setCh(char ch);
    [[nodiscard]] const Color &getColor() const;
    void setColor(const Color &color);
    [[nodiscard]] std::string to_string() const;
};

std::ostream &operator<<(std::ostream &os, Point const &p);

#endif //UNTITLED1_POINT_H
