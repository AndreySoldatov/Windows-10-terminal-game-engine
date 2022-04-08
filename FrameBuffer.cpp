//
// Created by Andrey on 06.08.2021.
//

#include "FrameBuffer.h"

FrameBuffer::FrameBuffer() : width_(), height_(), buffer_() {}

FrameBuffer::FrameBuffer(u32 width, u32 height, char c, Color color) {
    width_ = width;
    height_ = height;

    buffer_ = std::vector<std::vector<Pixel>>
            (
                    height_,
                    std::vector<Pixel>(
                            width_,
                            Pixel(c, color)
                    )
            );
}

void FrameBuffer::clear(char c, Color color) {
    for (auto &y : buffer_) {
        for (auto &x : y) {
            x = Pixel(c, color);
        }
    }
}

void FrameBuffer::set_point(Point point) {
    if(point.pos.x >= 0 && point.pos.x < width_ && point.pos.y >= 0 && point.pos.y < height_) {
        buffer_[point.pos.y][point.pos.x] = Pixel(point.ch, point.color);
    }
}

u32 FrameBuffer::get_width() const {
    return width_;
}

u32 FrameBuffer::get_height() const {
    return height_;
}

void FrameBuffer::display(ConsoleHandler const &handler, u32 millis) const {
    std::string out;
    //out.reserve(width_ * 20 * height_);
    handler.set_cursor(Vec2i(0, 0));
    for (auto &y : buffer_) {
        for (auto &x : y) {
            out += "\x1b[38;2;" + x.color.toEscFormat() + "m";
            out += x.c;
            out += ' ';
        }
        out += '\n';
    }
    out.pop_back();
    handler.printString(out.c_str());
    if(millis > 0) handler.sleep(millis);
}

FrameBuffer::FrameBuffer(Vec2i size, char c, Color color) {
    if(size.x >= 0 && size.y >= 0) {
        width_ = size.x;
        height_ = size.y;
    } else {
        width_ = 0;
        height_ = 0;
    }

    buffer_ = std::vector<std::vector<Pixel>>
            (
                    height_,
                    std::vector<Pixel>(
                            width_,
                            Pixel(c, color)
                    )
            );
}

Pixel FrameBuffer::at(Vec2u pos) const {
    if(pos.x >= 0 && pos.x < width_ && pos.y >= 0 && pos.y < height_)
        return buffer_[pos.y][pos.x];
    return Pixel('\0', Color());
}

void FrameBuffer::impose(FrameBuffer const &frameBuffer, Vec2i offset) {
    for (u32 y = 0; y < frameBuffer.get_height(); ++y) {
        for (u32 x = 0; x < frameBuffer.get_width(); ++x) {
            if(y + offset.y < height_ && x + offset.x < width_)
                buffer_[y + offset.y][x + offset.x] = frameBuffer.at(Vec2u(static_cast<int>(x), static_cast<int>(y)));
        }
    }
}
