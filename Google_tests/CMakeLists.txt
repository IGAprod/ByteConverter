cmake_minimum_required(VERSION 3.25)

project(GoogleTests C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(Headers
#        convert_test.h
#        ../ByteCodeConverter/ByteCodeConverter.h
#        ../Utilities/Utilities.h
#)
#
#set(Sources
#        convert_test.cpp
#        ../ByteCodeConverter/ByteCodeConverter.cpp
#        ../Utilities/Utilities.cpp
#)

include_directories(../ lib/googletest-main/googletest/include lib/googletest-main/googlemock/include ../ByteCodeConverter ../Utilities ../resources)

find_package(GTest REQUIRED)

add_executable(GoogleTests convert_test.cpp convert_test.cpp ../ByteCodeConverter/ByteCodeConverter.cpp ../Utilities/Utilities.cpp)
target_link_libraries(GoogleTests gtest gtest_main gmock)

add_test(
        NAME GoogleTests
        COMMAND GoogleTests
)