#include "gtest/gtest.h"
#include "../header/User.hpp"
#include "../header/Movie.hpp"
#include <string>

TEST(UserTests, CreateNewUser) {
    User testUser("test");
    Movie testMovie;
    testMovie.set_name("TEST123");
    testMovie.set_year(1981);
    testMovie.set_rating("R");
    testMovie.set_hour(2);
    testMovie.set_min(20);
    testMovie.set_genre("Action");
    testMovie.set_director("Obama", 1);
    testMovie.set_cast("Romney", 1);
    testUser.get_movie_list().add_movie(testMovie);
    testUser.get_movie_list().add_movie(testMovie);
    EXPECT_EQ(testUser.get_movie_list().get_size(), 2);
    EXPECT_EQ(testUser.get_movie_list().get_movie(0).get_name(), "TEST123");

    Review testReview("Titanic", "Very sad. I cried. What a sad movie.", 5);
    testUser.get_review_list().add_review(testReview);
    EXPECT_EQ(testUser.get_review_list().get_size(), 1);
    EXPECT_EQ(testUser.get_review_list().get_review(0).get_name(), "Titanic");
    EXPECT_EQ(testUser.get_review_list().get_review(0).get_review(), "Very sad. I cried. What a sad movie.");
    EXPECT_EQ(testUser.get_review_list().get_review(0).get_score(), 5);

}

TEST(UserTests, LoadNewUser) {
    User testUser("test");
    testUser.load_movie_list();
    testUser.load_review_list();
    EXPECT_EQ(testUser.get_movie_list().get_size(), 2);
    EXPECT_EQ(testUser.get_review_list().get_size(), 1);
}

