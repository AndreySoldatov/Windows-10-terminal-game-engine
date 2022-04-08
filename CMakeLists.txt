cmake_minimum_required(VERSION 3.15)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        untitled1
        main.cpp
        FrameBuffer.cpp
        FrameBuffer.h
        Point.cpp
        Point.h
        Vec2i.cpp
        Vec2i.h
        Defines.h
        ConsoleHandler.cpp
        ConsoleHandler.h
        Vec2u.cpp
        Vec2u.h
        RectangleShape.cpp
        RectangleShape.h
        TextField.cpp
        TextField.h
        BitmapPlusPlus.hpp
        ImageField.cpp
        ImageField.h
        EventHandler.cpp
        EventHandler.h
        Clock.cpp
        Clock.h
        Color.cpp
        Color.h
        Sound.cpp
        Sound.h
        BmpHandler.cpp
        BmpHandler.h
        ErrorHandler.cpp
        ErrorHandler.h
        Pixel.cpp
        Pixel.h
        Logger.cpp
        Logger.h
        LineShape.cpp LineShape.h)

target_link_libraries(untitled1 winmm.lib)