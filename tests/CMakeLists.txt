project(User_Tests)

cmake_minimum_required(VERSION 3.00)

add_subdirectory(googletest)

include_directories(
    ./tests/googletest/googletest/include/
    ./googletest/googlemock/include
    ./header
)

add_executable(runTests
    ../src
    test.cpp
)

target_link_libraries(runTests gmock gtest gtest_main)