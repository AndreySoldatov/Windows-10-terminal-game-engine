//
// Created by Andrey on 07.08.2021.
//

#include "RectangleShape.h"

RectangleShape::RectangleShape(
        Vec2u size,
        Vec2i pos,
        Color out_col,
        Color fill_col,
        char out_char,
        char fill_char) :
        pos_(pos),
        size_(size),
        outline_color_(out_col),
        fill_color_(fill_col),
        outline_char_(out_char),
        fill_char_(fill_char) {}

void RectangleShape::setSize(Vec2u size) {
    size_ = size;
}

void RectangleShape::setPos(Vec2i pos) {
    pos_ = pos;
}

void RectangleShape::move(Vec2i delta) {
    pos_ += delta;
}

void RectangleShape::setOutlineThickness(u32 thickness) {
    outline_thickness_ = thickness;
}

void RectangleShape::draw(FrameBuffer &buffer) const {
    for(i32 y = pos_.y; y < size_.y + pos_.y; y++) {
        for(i32 x = pos_.x; x < size_.x + pos_.x; x++) {
            buffer.set_point(Point(Vec2i(x, y), fill_char_, fill_color_));
        }
    }

    for(i32 x = pos_.x - static_cast<i32>(outline_thickness_);
        x < pos_.x + static_cast<i32>(size_.x + outline_thickness_);
        x++) {
        for(i32 y = pos_.y - static_cast<i32>(outline_thickness_);
            y < pos_.y;
            y++) {
            buffer.set_point(Point(Vec2i(x, y), outline_char_, outline_color_));
            buffer.set_point(Point(Vec2i(x, y + static_cast<i32>(size_.y + outline_thickness_)), outline_char_, outline_color_));
        }
    }

    for(i32 y = pos_.y; y < pos_.y + size_.y; y++) {
        for(i32 x = pos_.x - static_cast<i32>(outline_thickness_); x < pos_.x; x++) {
            buffer.set_point(Point(Vec2i(x, y), outline_char_, outline_color_));
            buffer.set_point(Point(Vec2i(x + static_cast<i32>(size_.x + outline_thickness_), y), outline_char_, outline_color_));
        }
    }
}

void RectangleShape::setOutlineColor(Color col) {
    outline_color_ = col;
}

void RectangleShape::setFillColor(Color col) {
    fill_color_ = col;
}

void RectangleShape::setOutlineChar(char c) {
    outline_char_ = c;
}

void RectangleShape::setFillChar(char c) {
    fill_char_ = c;
}

const Vec2i &RectangleShape::getPos() const {
    return pos_;
}

const Vec2u &RectangleShape::getSize() const {
    return size_;
}

const Color &RectangleShape::getOutlineColor() const {
    return outline_color_;
}

const Color &RectangleShape::getFillColor() const {
    return fill_color_;
}

char RectangleShape::getOutlineChar() const {
    return outline_char_;
}

char RectangleShape::getFillChar() const {
    return fill_char_;
}

unsigned int RectangleShape::getOutlineThickness() const {
    return outline_thickness_;
}
