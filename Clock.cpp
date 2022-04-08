//
// Created by Andrey on 08.08.2021.
//

#include "Clock.h"

Clock::Clock() {
    ticks_ = clock();
}

i32 Clock::restart() {
    i32 res = static_cast<i32>(1000.0 * (static_cast<float>(clock() - ticks_) / CLOCKS_PER_SEC));
    ticks_ = clock();
    return res;
}

i32 Clock::getElapsedTime() {
    return static_cast<i32>(1000.0 * (static_cast<float>(clock() - ticks_) / CLOCKS_PER_SEC));
}