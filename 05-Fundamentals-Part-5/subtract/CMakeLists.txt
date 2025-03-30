add_library(Subtract
    subtract/subtract.h
    subtract.c
)

target_include_directories(Add
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
