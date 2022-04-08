//
// Created by Andrey on 09.08.2021.
//

#ifndef UNTITLED1_ERRORHANDLER_H
#define UNTITLED1_ERRORHANDLER_H

#include <string>

class ErrorHandler {
    static std::string last_error_;
public:
    static const std::string& getLastError();
    static void setLastError(std::string const &error);
};


#endif //UNTITLED1_ERRORHANDLER_H
