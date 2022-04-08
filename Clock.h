//
// Created by Andrey on 08.08.2021.
//

#ifndef UNTITLED1_CLOCK_H
#define UNTITLED1_CLOCK_H

#include <ctime>

#include "Defines.h"

class Clock {
    i32 ticks_{};

public:
    Clock();
    i32 restart();
    i32 getElapsedTime();
};


#endif //UNTITLED1_CLOCK_H
