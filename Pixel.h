//
// Created by Andrey on 10.08.2021.
//

#ifndef UNTITLED1_PIXEL_H
#define UNTITLED1_PIXEL_H

#include "Color.h"

struct Pixel {
    char c{};
    Color color{};

    Pixel() = default;
    Pixel(char c, const Color &color);
};


#endif //UNTITLED1_PIXEL_H
