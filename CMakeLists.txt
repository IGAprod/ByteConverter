cmake_minimum_required(VERSION 3.25)

project(TestTask C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include_directories(Sources/Utilities resources)

add_executable(
        TestTask main.cpp
        Sources/Utilities/Utilities.cpp
        Sources/ByteCodeConverter/ByteCodeConverter.cpp
)