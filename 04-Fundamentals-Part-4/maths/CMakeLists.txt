add_library(Maths
    maths/maths.h
    maths.cpp
)

target_include_directories(Maths
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Maths
    PUBLIC
        Add
    PRIVATE
        Subtract
)
