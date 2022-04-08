//
// Created by Andrey on 11.08.2021.
//

#ifndef UNTITLED1_LOGGER_H
#define UNTITLED1_LOGGER_H

#include "Defines.h"

#include <fstream>
#include <ctime>

enum class LogLevel {
    INF,
    WAR,
    ERR,
};

class Logger {
    std::string filename_{};

public:
    Logger();
    explicit Logger(std::string const &filename);
    void log(std::string const &msg = "default info message", LogLevel logLevel = LogLevel::INF);
    void clearLog();
};


#endif //UNTITLED1_LOGGER_H
