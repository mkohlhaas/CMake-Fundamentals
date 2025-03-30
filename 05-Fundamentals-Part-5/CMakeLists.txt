cmake_minimum_required(VERSION 3.19)
project(Fundamentals)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(project_configuration)
include(print_target_libraries)

add_subdirectory(add)
add_subdirectory(subtract)
add_subdirectory(maths)

add_executable(Main main.cpp)
PrintTargetLibraries(Main "Before linking Maths:")
target_link_libraries(Main
    PRIVATE
        Maths
        ProjectConfiguration
)
PrintTargetLibraries(Main "After linking Maths:")
