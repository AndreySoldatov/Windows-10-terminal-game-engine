//
// Created by Andrey on 07.08.2021.
//

#include <wincon.h>
#include "EventHandler.h"

bool EventHandler::isKeyPressed(KEYCODE key) {
    return ((0x8000) & GetAsyncKeyState(key));
}

void EventHandler::getPressedKeys(std::vector<KEYCODE> &keyCodes) {
    keyCodes.clear();
    keyCodes.reserve(32);
    for(KEYCODE i = 0x00; i < 0xFF; i++) {
        if(EventHandler::isKeyPressed(i))
            keyCodes.push_back(i);
    }
}

Vec2u EventHandler::getMousePosition(ConsoleHandler const &handler) {
    INPUT_RECORD records[RECORD_COUNT];
    DWORD num_of_records{};
    //handler.getInputRecord(records, RECORD_COUNT, &num_of_records);

    for(ul i = 0; i < num_of_records; i++) {
        switch (records[i].EventType) {
            case MOUSE_EVENT:
                return Vec2u(records[i].Event.MouseEvent.dwMousePosition.X, records[i].Event.MouseEvent.dwMousePosition.Y);
        }
    }

    ErrorHandler::setLastError("I dont really know what happened but you didn't get the mouse pos");
    Logger l{"Lol"};
    l.log(ErrorHandler::getLastError() + ", " + std::to_string(num_of_records), LogLevel::ERR);
    return Vec2u();
}
