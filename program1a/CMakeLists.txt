cmake_minimum_required(VERSION 3.27)
project(program1a)

set(CMAKE_CXX_STANDARD 17)

add_executable(program1a main.cpp
        "Part 2/class.h"
        "Part 2/class.cpp"
        "Part 1/linkedLists.cpp"
        "Part 1/linkedLists.h"
        "Part 3/stl.cpp"
        "Part 3/stl.h"
)
