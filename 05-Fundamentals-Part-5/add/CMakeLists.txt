add_library(Add
    add/calc_status.h
    add/add.h
    add.cpp
)

target_include_directories(Add
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
