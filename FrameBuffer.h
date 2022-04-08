//
// Created by Andrey on 06.08.2021.
//

#ifndef UNTITLED1_FRAMEBUFFER_H
#define UNTITLED1_FRAMEBUFFER_H

#include <vector>
#include <iostream>
#include <utility>
#include <string>

#include "ConsoleHandler.h"
#include "Point.h"
#include "Color.h"
#include "Clock.h"
#include "Pixel.h"

class FrameBuffer {
private:
    u32 width_;
    u32 height_;
    std::vector<std::vector<Pixel>> buffer_;

public:
    FrameBuffer();
    FrameBuffer(u32 x, u32 y, char c = ' ', Color color = Color(256));
    explicit FrameBuffer(Vec2i size, char c = ' ', Color color = Color(256));

    void clear(char c, Color color = Color(256));
    void set_point(Point point);

    [[nodiscard]] u32 get_width() const;
    [[nodiscard]] u32 get_height()  const;

    [[nodiscard]] Pixel at(Vec2u pos) const;

    void impose(FrameBuffer const &frameBuffer, Vec2i offset = Vec2i());

    void display(ConsoleHandler const &handler, u32 millis = 0) const;
};

#endif //UNTITLED1_FRAMEBUFFER_H
