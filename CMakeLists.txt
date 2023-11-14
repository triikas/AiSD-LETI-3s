cmake_minimum_required(VERSION 3.26)
project(AiSD_LETI_3s)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab1-2 main.cpp Mword.h Universum.h)
add_executable(lab3 lab3.cpp
        Tree.h)