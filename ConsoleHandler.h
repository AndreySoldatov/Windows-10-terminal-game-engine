//
// Created by Andrey on 06.08.2021.
//

#ifndef UNTITLED1_CONSOLEHANDLER_H
#define UNTITLED1_CONSOLEHANDLER_H

#include <cwchar>
#include <windows.h>
#include <string>

#include "Color.h"
#include "Defines.h"
#include "Vec2i.h"
#include "ErrorHandler.h"
#include "Logger.h"

class ConsoleHandler {
    HANDLE hConsole_;
    Vec2u size_{};

public:
    explicit ConsoleHandler(std::string const &title = "default title", Vec2u const &size = Vec2u());
    ~ConsoleHandler();
    void set_color(Color c) const;
    void sleep(u32 millis) const;

    void set_cursor(Vec2i pos) const;
    void set_char_at_cursor(char c) const;
    [[nodiscard]] char get_char_at_cursor() const;

    void setTitle(std::string const &title) const;
    void flush() const;
    void toggleCursor(bool state) const;

    void resize(Vec2u const &size);
    [[nodiscard]] Vec2u getSize() const;

    void setConsoleFonstSize(Vec2u size) const;
    void printString(const char* str) const;

    [[deprecated("Not working currently")]] void getInputRecord(INPUT_RECORD *record, u32 record_count, ul *record_got) const;
};

#endif //UNTITLED1_CONSOLEHANDLER_H
