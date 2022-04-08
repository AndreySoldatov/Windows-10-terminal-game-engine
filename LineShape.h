//
// Created by Andrey on 11.08.2021.
//

#ifndef UNTITLED1_LINESHAPE_H
#define UNTITLED1_LINESHAPE_H

#include "Vec2i.h"
#include "FrameBuffer.h"
#include "Pixel.h"

class LineShape {
    Vec2i point1_{};
    Vec2i point2_{};
    Pixel pixel_{};

    LineShape() = default;
    LineShape(Vec2i const &p1, Vec2i const &p2, Pixel const &pixel = Pixel{});

    void setPointOne(Vec2i const &p);
    void setPointTwo(Vec2i const &p);

    [[nodiscard]] const Vec2i& getPointOne() const;
    [[nodiscard]] const Vec2i& getPointTwo() const;

    void setPixel(Pixel const &pixel);
    [[nodiscard]] const Pixel& getPixel() const;

    void draw(FrameBuffer const &buffer);
};


#endif //UNTITLED1_LINESHAPE_H
