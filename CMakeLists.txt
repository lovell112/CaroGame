cmake_minimum_required(VERSION 3.30)
project(Game__Caro)

set(CMAKE_CXX_STANDARD 20)

add_executable(Game__Caro main.cpp
        src/Player.cpp
        include/Player.h
        src/Board.cpp
        include/Board.h
        src/Game.cpp
        include/Game.h)
