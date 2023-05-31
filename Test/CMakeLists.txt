cmake_minimum_required(VERSION 3.25)

project(GoogleTests C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        ../Google_tests/lib/googletest-main/googletest/include
        ../Google_tests/lib/googletest-main/googlemock/include
        ../Sources/ByteCodeConverter
        ../Sources/Utilities
        ../resources
)

find_package(GTest REQUIRED)

add_executable(
        GoogleTests convert_test.cpp
        ../Sources/ByteCodeConverter/ByteCodeConverter.cpp
        ../Sources/Utilities/Utilities.cpp
)

target_link_libraries(GoogleTests gtest gtest_main gmock)

add_test(
        NAME GoogleTests
        COMMAND GoogleTests
)