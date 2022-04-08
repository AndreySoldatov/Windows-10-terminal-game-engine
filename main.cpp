#include <iostream>
#include <cmath>

#include "RectangleShape.h"
#include "Clock.h"
#include "EventHandler.h"
#include "Logger.h"
#include "ImageField.h"

int main() {
    ImageField image;
    if(!image.loadFromFile("tan.bmp", Vec2u(80, 40))) {
        std::cout << ErrorHandler::getLastError() << std::endl;
        return 1;
    }

    FrameBuffer buffer{image.getSize().x, image.getSize().y, '#', Color(50)};
    ConsoleHandler handler{"The Coooool game", image.getSize()};

    float a = 0.0f;

    while(!EventHandler::isKeyPressed(VK_ESCAPE)) {
        a += 1;
        image.draw(buffer);
        for(u32 y = 0; y < buffer.get_height(); y++) {
            for(u32 x = 0; x < buffer.get_width(); x++) {
                auto p = buffer.at(Vec2u(x, y));
                buffer.set_point(Point(
                        Vec2u(x, y).toVec2i(),
                        p.c,
                        p.color.blend(Color((u8)(std::sin(((float)x + a) / 4.0) * 128.0 + 128.0)), [](float a, float b) {return a * b;})
                        ));
            }
        }
        buffer.display(handler);
    }

    return 0;
}