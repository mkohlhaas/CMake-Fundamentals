cmake_minimum_required(VERSION 3.31)

project(Fundamentals)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(add)

function(PrintTargetLibraries target msg)
    get_target_property(linkedLibs ${target} LINK_LIBRARIES)
    get_target_property(interfaceLibs ${target} INTERFACE_LINK_LIBRARIES)
    message(STATUS "${msg}")
    message(STATUS "${target} LINK_LIBRARIES: ${linkedLibs}")
    message(STATUS "${target} INTERFACE_LINK_LIBRARIES: ${interfaceLibs}")
endfunction()

add_executable(Main main.cpp)
PrintTargetLibraries(Main "Before linking Add:")

# set_property(TARGET Main
#     APPEND
#     PROPERTY
#         LINK_LIBRARIES Add
# )
# set_property(TARGET Main
#     APPEND
#     PROPERTY
#         INTERFACE_LINK_LIBRARIES Add
# )

# set_target_properties(Main
#     PROPERTIES
#         LINK_LIBRARIES Add
#         INTERFACE_LINK_LIBRARIES Add
# )

target_link_libraries(Main
    PRIVATE
        Add
)
PrintTargetLibraries(Main "After linking Add:")
