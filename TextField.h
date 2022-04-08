//
// Created by Andrey on 07.08.2021.
//

#ifndef UNTITLED1_TEXTFIELD_H
#define UNTITLED1_TEXTFIELD_H

#include <string>

#include "Vec2i.h"
#include "Color.h"
#include "FrameBuffer.h"

class TextField {
    Vec2i pos_{};
    std::string str_{};

    Color color_{256};

public:
    TextField() = default;

    [[nodiscard]] const Vec2i &getPos() const;
    void setPos(const Vec2i &pos);
    [[nodiscard]] const std::string &getStr() const;
    void setStr(const std::string &str);
    [[nodiscard]] Color getTextColor() const;
    void setTextColor(Color textColor);
    [[nodiscard]]const Color &getColor() const;

    void draw(FrameBuffer &buffer) const;
};


#endif //UNTITLED1_TEXTFIELD_H
