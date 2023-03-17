#include "gtest/gtest.h"
#include "../header/Review.hpp"
#include "../header/ReviewList.hpp"
#include <sstream>

TEST (ReviewTests, ReviewConstructorAndGetter) {
    Review aReview("Brad", "Amazing movie!", 5);
    Review bReview("Joe", "Terrible Movie!", 1);
    EXPECT_NO_THROW(Review cReview("George", "The movie was okay", -3));
    EXPECT_TRUE(aReview.get_name() == "Brad");
    EXPECT_FALSE(aReview.get_review() == bReview.get_review());
    EXPECT_EQ(bReview.get_score(), 1);
}

TEST(ReviewTests, ReviewListConstructorAndGetter) {
    Review_List aRevs;
    Review aReview("Brad", "Amazing movie!", 5);
    Review bReview("Joe", "Terrible Movie!", 1);
    aRevs.add_review(aReview);
    aRevs.add_review(bReview);
    EXPECT_TRUE(aRevs.get_size() == 2);
    EXPECT_FALSE(aRevs.get_review(0).get_name() == aRevs.get_review(1).get_name());
}

TEST(ReviewTests, ReviewTestEdit) {
    Review aReview("Brad", "Amazing movie!", 5);
    aReview.set_review("Horrible Movie");
    EXPECT_TRUE(aReview.get_review() == "Horrible Movie");
    aReview.set_score(1);
    EXPECT_EQ(aReview.get_score(), 1);
}


TEST(ReviewTests, testPrint) {
    Review review("Test Restaurant", "Test Review", 5);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    review.print_review();

    std::cout.rdbuf(old);


    std::string expected_output = "Test Restaurant\nTest Review\n5\n";
    std::string actual_output = buffer.str();
    EXPECT_EQ(actual_output, expected_output);
}

TEST(ReviewTests, testName) {
    Review review("Test Name", "Test Review" , 4);

    review.set_score(3);
    int newScore = review.get_score();
    EXPECT_EQ(newScore, 3);
}