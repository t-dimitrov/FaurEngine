cmake_minimum_required(VERSION 3.22)
project(Sandbox
    LANGUAGES CXX
)

add_executable(Sandbox src/SandboxApp.cpp)

target_link_libraries(Sandbox PRIVATE FaurEngine)
target_include_directories(Sandbox PRIVATE ../FaurEngine/src/)

