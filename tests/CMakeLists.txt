project(User_Tests)

cmake_minimum_required(VERSION 3.00)

add_subdirectory(googletest)

include_directories(
    ./tests/googletest/googletest/include/
    ./googletest/googlemock/include
    ./header
)

add_executable(runTests
    ../src/User.cpp
    ../src/Movie.cpp
    ../src/MovieList.cpp
    ../src/Review.cpp
    ../src/ReviewList.cpp
    ../src/CastList.cpp
    ../src/CastMember.cpp
    ../src/UserMain.cpp
    test.cpp
)

add_executable(runUserMain
    ../src/User.cpp
    ../src/Movie.cpp
    ../src/MovieList.cpp
    ../src/Review.cpp
    ../src/ReviewList.cpp
    ../src/CastList.cpp
    ../src/CastMember.cpp
    ../src/UserMain.cpp
)

target_link_libraries(runTests gmock gtest gtest_main)