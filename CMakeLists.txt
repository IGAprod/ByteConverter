cmake_minimum_required(VERSION 3.25)
project(testing)

set(CMAKE_CXX_STANDARD 17)

SET(SOURCES
        Utilities/Utilities.cpp
        main.cpp
)

SET(HEADERS
        Utilities/Utilities.h
        ByteCodeConverter/ByteCodeConverter.h)

add_executable(testing main.cpp ByteCodeConverter/ByteCodeConverter.h Utilities/Utilities.h Utilities/Utilities.cpp ByteCodeConverter/ByteCodeConverter.cpp Google_tests/convert_test.cpp)

target_include_directories(testing
        PRIVATE
            ${PROJECT_SOURCE_DIR}/Utilities
)

add_subdirectory(Google_tests/lib/googletest-main)
add_subdirectory(Google_tests)