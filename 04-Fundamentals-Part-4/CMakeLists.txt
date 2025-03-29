cmake_minimum_required(VERSION 3.19)
project(Fundamentals)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

function(PrintTargetLibraries target msg)
    get_target_property(linkedLibs ${target} LINK_LIBRARIES)
    get_target_property(interfaceLibs ${target} INTERFACE_LINK_LIBRARIES)
    message(STATUS "${msg}")
    message(STATUS "${target} LINK_LIBRARIES: ${linkedLibs}")
    message(STATUS "${target} INTERFACE_LINK_LIBRARIES: ${interfaceLibs}")
endfunction()

add_subdirectory(add)
add_subdirectory(subtract)
add_subdirectory(maths)

add_executable(Main main.cpp)
PrintTargetLibraries(Main "Before linking Maths:")
target_link_libraries(Main
    PRIVATE
        Maths
)
PrintTargetLibraries(Main "After linking Maths:")
