include(FetchContent)

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(googletest)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "")

add_executable(testMaths ut_maths.cpp)

target_link_libraries(testMaths
    PRIVATE
        Maths
        ProjectConfiguration
        gtest
        gtest_main
)

# add_test(NAME testMaths COMMAND testMaths)

include(GoogleTest)

gtest_discover_tests(testMaths)
