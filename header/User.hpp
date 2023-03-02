#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "Movie_list.hpp"
#include "Review_list.hpp"

class User {
    private:
        std::string username;
        std::string password;
        Movie_list watched_movies;
        Review_list user_reviews;

    public:
        User(std::string name, std::string pass);
        Movie_list get_movie_list();
        Review_list get_reviews();
        void print_stats();
        void get_recommendations();
        std::string print_credentials();
};
#endif