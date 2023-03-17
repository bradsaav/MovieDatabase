#include "gtest/gtest.h"
#include "../header/Review.hpp"
#include "../header/ReviewList.hpp"

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

TEST(ReviewTests, ReviewListRemove) {
    Review_List reviews;
    Review aReview("Brad", "Amazing movie!", 5);
    reviews.add_review(aReview);
    reviews.remove_review("Brad", "Amazing movie!");
    EXPECT_EQ(reviews.get_size(), 0);
    Review bReview("Joe", "Terrible Movie!", 1);
    Review cReview("George", "The movie was okay!", 3);
    reviews.add_review(bReview);
    reviews.add_review(cReview);
    reviews.remove_review("Joe", "Terrible Movie!");
    EXPECT_TRUE(reviews.get_review(0).get_review() == "The movie was okay!");
    EXPECT_NO_THROW(reviews.remove_review("Joe", "Terrible Movie!"));
    

}
