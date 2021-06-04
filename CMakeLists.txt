cmake_minimum_required(VERSION 3.19)
project(CulinaryRecips)

set(CMAKE_CXX_STANDARD 14)

add_executable(CulinaryRecips main.cpp Recipe.cpp Recipe.h functions.cpp functions.h)