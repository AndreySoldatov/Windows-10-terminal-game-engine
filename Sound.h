//
// Created by Andrey on 08.08.2021.
//

#ifndef UNTITLED1_SOUND_H
#define UNTITLED1_SOUND_H

#include <string>
#include <windows.h>

class Sound {
    std::string filename_;
public:
    Sound() = default;
    explicit Sound(std::string const &filename);
    void setFilename(std::string const &filename);
    void play() const;
    void stop() const;
};


#endif //UNTITLED1_SOUND_H
