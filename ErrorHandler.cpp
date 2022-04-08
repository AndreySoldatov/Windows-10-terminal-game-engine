//
// Created by Andrey on 09.08.2021.
//

#include "ErrorHandler.h"

std::string ErrorHandler::last_error_;

const std::string &ErrorHandler::getLastError() {
    return last_error_;
}

void ErrorHandler::setLastError(std::string const &error) {
    last_error_ = error;
}