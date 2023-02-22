cmake_minimum_required(VERSION 3.21)
project(Gravity)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gravity src/main.cpp)
target_link_libraries(Gravity PUBLIC sfml-graphics sfml-system sfml-window)
