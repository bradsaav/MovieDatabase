cmake_minimum_required(VERSION 3.20)
add_subdirectory(googletest)

# set(CMAKE_CXX_FLAGS --coverage)

add_executable(test
    CastTest.cpp
    ../src/CastMember.cpp
    ../src/CastList.cpp
    ../src/Review.cpp
    ../src/ReviewList.cpp
)

target_link_libraries(test gtest gtest_main)