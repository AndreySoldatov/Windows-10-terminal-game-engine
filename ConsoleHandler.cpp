//
// Created by Andrey on 06.08.2021.
//

#include "ConsoleHandler.h"

ConsoleHandler::ConsoleHandler(std::string const &title, Vec2u const &size) : hConsole_(GetStdHandle(STD_OUTPUT_HANDLE)) {
    this->setTitle(title);
    this->flush();
    if(size != Vec2u()) this->resize(size);
    this->toggleCursor(false);
}

void ConsoleHandler::set_color(Color c) const {
    std::cout << "\x1b[38;2;" + c.toEscFormat() + "m";
}

void ConsoleHandler::sleep(unsigned int millis) const {
    Sleep(millis);
}

void ConsoleHandler::setTitle(std::string const &title) const {
    SetConsoleTitleA(title.c_str());
}

void ConsoleHandler::set_cursor(Vec2i pos) const {
    COORD coord;
    coord.X = pos.x;
    coord.Y = pos.y;
    SetConsoleCursorPosition(hConsole_, coord);
}

void ConsoleHandler::set_char_at_cursor(char c) const {
    std::cout << c;
}

char ConsoleHandler::get_char_at_cursor() const {
    char c = '\0';
    CONSOLE_SCREEN_BUFFER_INFO con;
    DWORD read = 0;
    ReadConsoleOutputCharacterA(hConsole_, &c, 1, con.dwCursorPosition, &read);
    return c;
}

void ConsoleHandler::flush() const {
    system("cls");
}

void ConsoleHandler::resize(Vec2u const &size) {
    size_ = size;

    COORD params;
    params.X = size.x * 2 + 10;
    params.Y = size.y + 10;
    SetConsoleScreenBufferSize(hConsole_, params);

    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = size.x * 2 - 1;
    rect.Bottom = size.y - 1;
    SetConsoleWindowInfo(hConsole_, TRUE, &rect);
}

Vec2u ConsoleHandler::getSize() const {
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hConsole_, &info);
    return Vec2u((info.srWindow.Right - info.srWindow.Left + 1) / 2,
            info.srWindow.Bottom - info.srWindow.Top);
}

void ConsoleHandler::toggleCursor(bool state) const {
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(hConsole_, &info);
    info.bVisible = state;
    SetConsoleCursorInfo(hConsole_, &info);
}

void ConsoleHandler::setConsoleFonstSize(Vec2u size) const {
    //TODO:
}

ConsoleHandler::~ConsoleHandler() {
    this->set_color(Color(256));
    this->toggleCursor(true);
}

void ConsoleHandler::printString(const char *str) const {
    WriteConsole(hConsole_, str, strlen(str), nullptr, nullptr);
}

void ConsoleHandler::getInputRecord(INPUT_RECORD *record, u32 record_count, ul *record_got) const {
    HANDLE hConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
    ReadConsoleInput(hConsoleIn, record, record_count, record_got);
}
