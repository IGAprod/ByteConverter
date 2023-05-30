cmake_minimum_required(VERSION 3.25)

project(TestTask C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/Utilities ${PROJECT_SOURCE_DIR}/resources)
#add_subdirectory(Google_tests)

#SET(Headers
#        Utilities/Utilities.h
#        ByteCodeConverter/ByteCodeConverter.h
#)
#
#SET(Sources
#        Utilities/Utilities.cpp
#        main.cpp
#)

add_executable(TestTask main.cpp Utilities/Utilities.cpp ByteCodeConverter/ByteCodeConverter.cpp) #Google_tests/convert_test.cpp