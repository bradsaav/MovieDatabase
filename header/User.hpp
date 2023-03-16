#ifndef __USER_HPP__
#define __USER_HPP__

#include <string>
#include <iostream>
#include "MovieList.hpp"
#include "ReviewList.hpp"

class User {
    private:
        std::string username;
        std::string password;
        Movie_List watched_movies;
        Review_List user_reviews;
        void load_movie_list();
        void load_review_list();

    public:
        User(std::string name, std::string pass);
        Movie_List get_movie_list();
        Review_List get_review_list();
        std::string print_credentials();
};
#endif