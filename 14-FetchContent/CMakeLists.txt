cmake_minimum_required(VERSION 3.14)

project(FetchExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG release-1.10.0)

FetchContent_MakeAvailable(googletest)

# FetchContent_GetProperties(googletest) if (NOT googletest_POPULATED)
# FetchContent_Populate(googletest)
#
# # Perform arbitrary actions on the googletest project
#
# add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR}) endif()

set(FETCHCONTENT_UPDATES_DISCONNECTED
    ON CACHED BOOL "Do not update everytime I run cmake, please")
