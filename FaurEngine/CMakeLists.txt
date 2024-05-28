cmake_minimum_required(VERSION 3.22)
project(FaurEngine
    VERSION 0.0.1
    LANGUAGES CXX
)

add_library(FaurEngine STATIC
    src/Faur/Core/Application.cpp
)
target_include_directories(FaurEngine PUBLIC src/)

