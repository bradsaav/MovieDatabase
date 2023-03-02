#include "gtest/gtest.h"
//#include "gmock/gmock.h"
#include "../header/User.hpp"
#include "../header/Movie_list.hpp"
#include "../header/Review_list.hpp"

TEST(MovieTests, ConstructorTest) {
    User newUser("Bob", "password");
    EXPECT_EQ(newUser.print_credentials(), "Bob password");
}