#include "gtest/gtest.h"
//#include "gmock/gmock.h"
#include "../header/Movie.hpp"
#include "../header/MovieList.hpp"

TEST (MovieTests, testConstructorAndGetter) {
    Movie m;
 
    EXPECT_TRUE(m.get_name() == "");
    EXPECT_EQ(m.get_release_year(), 0);
    EXPECT_TRUE(m.get_rating() == "");
    EXPECT_EQ(m.get_hour(), 0);
    EXPECT_EQ(m.get_minute(), 0);
    EXPECT_EQ(m.get_genre().size(), 0);
    EXPECT_EQ(m.get_director().get_size(), 0);
    EXPECT_EQ(m.get_cast().get_size(), 0);
}

TEST (MovieTests, testSetterAndSomeGetter) {
    Movie m;

    m.set_name("Indiana Jones and the Raiders of the Lost Ark");
    m.set_year(1981);
    m.set_rating("PG");
    m.set_hour(1);
    m.set_min(55);
    m.set_genre("Action");
    m.set_genre("Adventure");
    m.set_director("Steven Spielberg", 76);
    m.set_cast("Harrison Ford", 81);
    m.set_cast("Karen Allen", 71);
    m.set_cast("Paul Freeman", 80);

    EXPECT_TRUE(m.get_name() == "Indiana Jones and the Raiders of the Lost Ark");
    EXPECT_EQ(m.get_release_year(), 1981);
    EXPECT_TRUE(m.get_rating() == "PG");
    EXPECT_EQ(m.get_hour(), 1);
    EXPECT_EQ(m.get_minute(), 55);
    EXPECT_EQ(m.get_genre().size(), 2);
    EXPECT_TRUE(m.get_genre().at(0) == "Action");
    EXPECT_TRUE(m.get_genre().at(1) == "Adventure");

    EXPECT_EQ(m.get_director().get_size(), 1);
    EXPECT_TRUE(m.get_director().get_CastMember(0).get_name() == "Steven Spielberg");
    EXPECT_EQ(m.get_director().get_CastMember(0).get_age(), 76);

    EXPECT_EQ(m.get_cast().get_size(), 3);
    EXPECT_TRUE(m.get_cast().get_CastMember(0).get_name() == "Harrison Ford");
    EXPECT_EQ(m.get_cast().get_CastMember(0).get_age(), 81);
    EXPECT_TRUE(m.get_cast().get_CastMember(1).get_name() == "Karen Allen");
    EXPECT_EQ(m.get_cast().get_CastMember(1).get_age(), 71);
    EXPECT_TRUE(m.get_cast().get_CastMember(2).get_name() == "Paul Freeman");
    EXPECT_EQ(m.get_cast().get_CastMember(2).get_age(), 80);
}

TEST (MovieTests, addMovieTest) {
    Movie m;
    Movie_List ml;

    EXPECT_EQ(ml.get_size(), 0);

    m.set_name("Indiana Jones and the Raiders of the Lost Ark");
    m.set_year(1981);
    m.set_rating("PG");
    m.set_hour(1);
    m.set_min(55);
    m.set_genre("Action");
    m.set_genre("Adventure");
    m.set_director("Steven Spielberg", 76);
    m.set_cast("Harrison Ford", 81);
    m.set_cast("Karen Allen", 71);
    m.set_cast("Paul Freeman", 80);

    ml.add_movie(m);

    EXPECT_EQ(ml.get_size(), 1);
}

TEST (MovieTests, removeMovieTest) {
    Movie m;
    Movie_List ml;

    EXPECT_EQ(ml.get_size(), 0);

    m.set_name("Indiana Jones and the Raiders of the Lost Ark");
    m.set_year(1981);
    m.set_rating("PG");
    m.set_hour(1);
    m.set_min(55);
    m.set_genre("Action");
    m.set_genre("Adventure");
    m.set_director("Steven Spielberg", 76);
    m.set_cast("Harrison Ford", 81);
    m.set_cast("Karen Allen", 71);
    m.set_cast("Paul Freeman", 80);

    ml.add_movie(m);

    EXPECT_EQ(ml.get_size(), 1);

    ml.remove_movie(m.get_name(), m.get_release_year());

    EXPECT_EQ(ml.get_size(), 0);
}
