//
// Created by Andrey on 06.08.2021.
//

#include "Point.h"

Point::Point() : pos(), ch(), color(256) {}

Point::Point(i32 x, i32 y, char c, Color col) : pos(x, y), ch(c), color(col) {}

Point::Point(Vec2i pos, char c, Color col) : pos(pos), ch(c), color(col) {}

std::string Point::to_string() const {
    return std::string("(") +
           pos.to_string() +
           ", \"" +
           ch +
           "\", " +
           color.toEscFormat() +
           ")";
}

const Vec2i &Point::getPos() const {
    return pos;
}

void Point::setPos(const Vec2i &p) {
    Point::pos = p;
}

char Point::getCh() const {
    return ch;
}

void Point::setCh(char c) {
    Point::ch = c;
}

const Color &Point::getColor() const {
    return color;
}

void Point::setColor(const Color &c) {
    Point::color = c;
}

std::ostream &operator<<(std::ostream &os, Point const &p) {
    return os << p.to_string();
}
