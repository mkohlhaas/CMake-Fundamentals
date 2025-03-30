set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(ProjectConfiguration INTERFACE)
target_compile_options(ProjectConfiguration
    INTERFACE
        -Wall
        -Wextra
        $<$<COMPILE_LANGUAGE:CXX>:-Weffc++>  # generator expression
)
target_compile_features(ProjectConfiguration
    INTERFACE
        cxx_std_17
)
