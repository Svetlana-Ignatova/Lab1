cmake_minimum_required(VERSION 3.17)
project(Svetalab C)

set(CMAKE_C_STANDARD 11)

add_executable(Svetalab main.c array.h array.c CException.h CException.c examples.h examples.c)