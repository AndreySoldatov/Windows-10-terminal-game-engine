//
// Created by Andrey on 07.08.2021.
//

#include "TextField.h"

const Vec2i &TextField::getPos() const {
    return pos_;
}

void TextField::setPos(const Vec2i &pos) {
    pos_ = pos;
}

const std::string &TextField::getStr() const {
    return str_;
}

void TextField::setStr(const std::string &str) {
    str_ = str;
}

Color TextField::getTextColor() const {
    return color_;
}

void TextField::setTextColor(Color textColor) {
    color_ = textColor;
}

void TextField::draw(FrameBuffer &buffer) const {
    Vec2i pos = pos_;
    for(auto &i : str_) {
        if(i == '\n') {
            pos.x = pos_.x;
            pos.y++;
        }
        else if(i == 9 /*TAB*/) {
            buffer.set_point(Point(pos, ' ', color_));
            buffer.set_point(Point(pos + Vec2i(1, 0), ' ', color_));
            buffer.set_point(Point(pos + Vec2i(2, 0), ' ', color_));
            buffer.set_point(Point(pos + Vec2i(3, 0), ' ', color_));
            pos.x+=4;
        }
        else {
            buffer.set_point(Point(pos, i, color_));
            pos.x++;
        }
    }
}

const Color &TextField::getColor() const {
    return color_;
}
