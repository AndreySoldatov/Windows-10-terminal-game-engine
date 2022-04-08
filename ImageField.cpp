//
// Created by Andrey on 07.08.2021.
//

#include "ImageField.h"

#include "ErrorHandler.h"

bool ImageField::loadFromFile(std::string const &filename) {
    bmp::Bitmap image;
    if(image.Load(filename)) {
        size_.x = image.Width();
        size_.y = image.Height();
        frameBuffer_ = FrameBuffer(image.Width(), image.Height());
        for(i32 y = 0; y < image.Height(); y++) {
            for(i32 x = 0; x < image.Width(); x++) {
                bmp::Pixel px = image.Get(x, y);
                Color c(px.r, px.g, px.b);
                frameBuffer_.set_point(Point(x, y, fillChar_, c));
            }
        }
        return true;
    }
    ErrorHandler::setLastError("Could not load an image!");
    return false;
}

bool ImageField::loadFromFile(std::string const &filename, Vec2u size) {
    size_ = size;
    bmp::Bitmap image;
    if(image.Load(filename)) {
        auto width = image.Width();
        auto height = image.Height();
        frameBuffer_ = FrameBuffer(width, height);
        for(i32 y = 0; y < static_cast<i32>(size.y); y++) {
            for(i32 x = 0; x < static_cast<i32>(size.x); x++) {
                bmp::Pixel px = image.Get(
                        static_cast<int>(static_cast<float>(width) * static_cast<float>(x) / static_cast<float>(size.x)),
                        static_cast<int>(static_cast<float>(height) * static_cast<float>(y) / static_cast<float>(size.y))
                        );
                Color c(px.r, px.g, px.b);
                frameBuffer_.set_point(Point(x, y, fillChar_, c));
            }
        }
        return true;
    }
    return false;
}

void ImageField::setFillChar(char fill_char) {
    fillChar_ = fill_char;
}

void ImageField::setPos(Vec2i pos) {
    pos_ = pos;
}

void ImageField::draw(FrameBuffer &buffer) {
    buffer.impose(frameBuffer_, pos_);
}

const Vec2i &ImageField::getPos() const {
    return pos_;
}

const Vec2u &ImageField::getSize() const {
    return size_;
}

char ImageField::getFillChar() const {
    return fillChar_;
}

void ImageField::blend(Color c, std::function<float(float, float)> const &f) {
    for(u32 y = 0; y < size_.y; y++) {
        for(u32 x = 0; x < size_.x; x++) {
            auto col = frameBuffer_.at(Vec2u(x, y));
            frameBuffer_.set_point(Point(Vec2i(x, y), col.c , col.color.blend(c, f)));
        }
    }
}

void ImageField::lerpByBrightness(Color c1, Color c2) {
    for(u32 y = 0; y < size_.y; y++) {
        for(u32 x = 0; x < size_.x; x++) {
            auto col = frameBuffer_.at(Vec2u(x, y));
            frameBuffer_.set_point(Point(Vec2i(x, y), col.c , c1.lerp(c2, col.color.brightness())));
        }
    }
}
