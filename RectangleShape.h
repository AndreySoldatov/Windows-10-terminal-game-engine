//
// Created by Andrey on 07.08.2021.
//

#ifndef UNTITLED1_RECTANGLESHAPE_H
#define UNTITLED1_RECTANGLESHAPE_H

#include "Defines.h"

#include "Color.h"
#include "Vec2i.h"
#include "Vec2u.h"
#include "FrameBuffer.h"
#include "Point.h"

class RectangleShape {
    Vec2i pos_{};
    Vec2u size_{};

    Color outline_color_{256};
    Color fill_color_{256};

    char outline_char_{'#'};
    char fill_char_{' '};

    u32 outline_thickness_{1};

public:
    RectangleShape() = default;
    explicit RectangleShape(
            Vec2u size,
            Vec2i pos = Vec2i(),
            Color out_col = Color(256),
            Color fill_col = Color(256),
            char out_char = '#',
            char fill_char = ' ');

    void setSize(Vec2u size);
    void setPos(Vec2i pos);

    [[nodiscard]] const Vec2i &getPos() const;
    [[nodiscard]] const Vec2u &getSize() const;
    [[nodiscard]] const Color &getOutlineColor() const;
    [[nodiscard]] const Color &getFillColor() const;
    [[nodiscard]] char getOutlineChar() const;
    [[nodiscard]] char getFillChar() const;
    [[nodiscard]] u32 getOutlineThickness() const;

    void move(Vec2i delta);
    void setOutlineThickness(u32 thickness);

    void setOutlineColor(Color col);
    void setFillColor(Color col);
    void setOutlineChar(char c);
    void setFillChar(char c);

    void draw(FrameBuffer &buffer) const;
};


#endif //UNTITLED1_RECTANGLESHAPE_H
