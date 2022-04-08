//
// Created by Andrey on 11.08.2021.
//

#include "Logger.h"

Logger::Logger() {
    time_t t = time(nullptr);
    auto local = localtime(&t);
    filename_ += std::string("Log_") +
                 std::to_string(local->tm_year + 1900) +
                 "-" +
                 std::to_string(local->tm_mon) +
                 "-" +
                 std::to_string(local->tm_mday) +
                 ".txt";
}

Logger::Logger(std::string const &filename) {
    filename_ = filename + ".txt";
}

void Logger::log(const std::string &msg, LogLevel logLevel) {
    std::ofstream file_handler{filename_, std::ofstream::app};
    switch(logLevel) {
        case LogLevel::INF:
            file_handler << "[INFO]: ";
            break;
        case LogLevel::WAR:
            file_handler << "[WARNING]: ";
            break;
        case LogLevel::ERR:
            file_handler << "[ERROR]: ";
            break;
    }
    file_handler << msg << "\n";
    file_handler.close();
}

void Logger::clearLog() {
    std::ofstream file_handler{filename_, std::ofstream::trunc};
    file_handler.close();
}
