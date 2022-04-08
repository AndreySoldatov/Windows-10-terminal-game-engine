//
// Created by Andrey on 07.08.2021.
//

#ifndef UNTITLED1_IMAGEFIELD_H
#define UNTITLED1_IMAGEFIELD_H

#include <vector>
#include <string>

#include "FrameBuffer.h"
#include "BitmapPlusPlus.hpp"
#include "Vec2i.h"

class ImageField {
    Vec2i pos_{};
    Vec2u size_{};
    FrameBuffer frameBuffer_{};
    char fillChar_{'#'};

public:
    ImageField() = default;
    bool loadFromFile(std::string const &filename);
    bool loadFromFile(std::string const &filename, Vec2u size);
    void setFillChar(char fill_char);
    void setPos(Vec2i pos);

    [[nodiscard]] const Vec2i &getPos() const;
    [[nodiscard]] const Vec2u &getSize() const;
    [[nodiscard]] char getFillChar() const;

    void blend(Color c, std::function<float(float, float)> const &f);
    void lerpByBrightness(Color c1, Color c2);

    void draw(FrameBuffer &buffer);
};


#endif //UNTITLED1_IMAGEFIELD_H
