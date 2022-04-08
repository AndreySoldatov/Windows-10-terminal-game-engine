//
// Created by Andrey on 11.08.2021.
//

#include "LineShape.h"

LineShape::LineShape(Vec2i const &p1, Vec2i const &p2, Pixel const &pixel) : point1_(p1), point2_(p1), pixel_(pixel) {}

void LineShape::setPointOne(Vec2i const &p) {
    point1_ = p;
}

void LineShape::setPointTwo(Vec2i const &p) {
    point2_ = p;
}

const Vec2i &LineShape::getPointOne() const {
    return point1_;
}

const Vec2i &LineShape::getPointTwo() const {
    return point2_;
}

void LineShape::setPixel(Pixel const &pixel) {
    pixel_ = pixel;
}

const Pixel &LineShape::getPixel() const {
    return pixel_;
}

void LineShape::draw(FrameBuffer const &buffer) {
    //TODO:
}
