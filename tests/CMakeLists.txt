cmake_minimum_required(VERSION 3.20)
add_subdirectory(googletest)

# set(CMAKE_CXX_FLAGS --coverage)

add_executable(CastTest
    CastTest.cpp
    ../src/Movie.cpp
    ../src/MovieList.cpp
    ../src/CastMember.cpp
    ../src/CastList.cpp
    ../src/Review.cpp
    ../src/ReviewList.cpp
)

add_executable(MovieTest
    MovieTest.cpp
    ../src/Movie.cpp
    ../src/MovieList.cpp
    ../src/CastMember.cpp
    ../src/CastList.cpp
    ../src/Review.cpp
    ../src/ReviewList.cpp
)

target_link_libraries(CastTest gtest gtest_main)
target_link_libraries(MovieTest gtest gtest_main)