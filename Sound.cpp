//
// Created by Andrey on 08.08.2021.
//

#include "Sound.h"

void Sound::play() const {
    PlaySound(TEXT(filename_.c_str()), nullptr, SND_ASYNC);
}

Sound::Sound(std::string const &filename) {
    filename_ = filename;
}

void Sound::stop() const {
    PlaySound(nullptr, nullptr, 0);
}

void Sound::setFilename(std::string const &filename) {
    filename_ = filename;
}
