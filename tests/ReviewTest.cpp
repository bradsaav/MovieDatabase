#include "gtest/gtest.h"
#include "../header/Review.h"
#include "../header/ReviewList.hpp"

TEST (ReviewTests, ReviewConstructorAndGetter) {
    Review aReview("Brad", "Amazing movie!", 5);
    Review bReview("Joe", "Terrible Movie!", 1);
    EXPECT_NO_THROW(Review cReview("George", "The movie was okay", -3));
    EXPECT_TRUE(aReview.getName() == "Brad");
    EXPECT_FALSE(aReview.getReview() == bReview.getReview());
    EXPECT_EQ(bReview.getScore(), 1);
}

TEST(ReviewTests, ReviewListConstructorAndGetter) {
    ReviewList aRevs;
    Review aReview("Brad", "Amazing movie!", 5);
    Review bReview("Joe", "Terrible Movie!", 1);
    aRevs.add_Review(aReview);
    aRevs.add_Review(bReview);
    EXPECT_TRUE(aRevs.get_size() == 2);
    EXPECT_FALSE(aRevs.get_Review(0).getName() == aRevs.get_Review(1).getName());
}

TEST(ReviewTests, ReviewTestEdit) {
    Review aReview("Brad", "Amazing movie!", 5);
    aReview.editReview("Horrible Movie");
    EXPECT_TRUE(aReview.getReview() == "Horrible Movie");
    aReview.editScore(1);
    EXPECT_EQ(aReview.getScore(), 1);
}

TEST(ReviewTests, ReviewListRemove) {
    ReviewList reviews;
    Review aReview("Brad", "Amazing movie!", 5);
    reviews.add_Review(aReview);
    reviews.remove_Review("Brad", "Amazing movie!");
    EXPECT_EQ(reviews.get_size(), 0);
    Review bReview("Joe", "Terrible Movie!", 1);
    Review cReview("George", "The movie was okay!", 3);
    reviews.add_Review(bReview);
    reviews.add_Review(cReview);
    reviews.remove_Review("Joe", "Terrible Movie!");
    EXPECT_TRUE(reviews.get_Review(0).getReview() == "The movie was okay!");
    EXPECT_NO_THROW(reviews.remove_Review("Joe", "Terrible Movie!"));
    

}
