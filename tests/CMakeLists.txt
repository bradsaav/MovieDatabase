project(User_Tests)

cmake_minimum_required(VERSION 3.00)

add_subdirectory(googletest)

add_executable(test
    CastTest.cpp
    MovieTest.cpp
    ReviewTest.cpp
    UserTest.cpp
    ../src/User.cpp
    ../src/Movie.cpp
    ../src/MovieList.cpp
    ../src/Review.cpp
    ../src/ReviewList.cpp
    ../src/CastList.cpp
    ../src/CastMember.cpp
)

target_link_libraries(test gtest gtest_main)