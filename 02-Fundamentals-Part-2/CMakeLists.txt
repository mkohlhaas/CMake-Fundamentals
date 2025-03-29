cmake_minimum_required(VERSION 3.31)

project(Fundamentals)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(Main main.cpp)

target_link_libraries(Main
    PRIVATE
        Add
)

# add_library(Add OBJECT add.cpp)
add_library(Add add.cpp)

