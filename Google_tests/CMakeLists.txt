
project(testing)

include_directories(../ lib/googletest-main/googletest/include lib/googletest-main/googlemock/include/gmock)

find_package(GTest REQUIRED)

add_executable(convert_test convert_test.cpp)
target_link_libraries(testing gtest gtest_main)