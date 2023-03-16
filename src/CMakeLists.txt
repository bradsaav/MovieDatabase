cmake_minimum_required(VERSION 3.20)

# set(CMAKE_CXX_FLAGS --coverage)

add_executable(runProgram
    MovieMain.cpp
    Movie.cpp
    MovieList.cpp
    CastMember.cpp
    CastList.cpp
    Review.cpp
    ReviewList.cpp
    DisplayRecommendations.cpp
)