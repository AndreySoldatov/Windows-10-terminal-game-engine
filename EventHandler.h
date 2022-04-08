//
// Created by Andrey on 07.08.2021.
//

#ifndef UNTITLED1_EVENTHANDLER_H
#define UNTITLED1_EVENTHANDLER_H

#define RECORD_COUNT 128
#define KEYCODE unsigned short

#include <windows.h>
#include <vector>

#include "Vec2u.h"
#include "ConsoleHandler.h"
#include "Logger.h"

class EventHandler {
public:
    static bool isKeyPressed(KEYCODE key);
    static void getPressedKeys(std::vector<KEYCODE> &keyCodes);
    [[deprecated("Not working currently")]] static Vec2u getMousePosition(ConsoleHandler const &handler);
};


#endif //UNTITLED1_EVENTHANDLER_H
