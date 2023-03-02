#ifndef MOVIE_LIST_H
#define MOVIE_LIST_H

#include <string>
#include <iostream>
#include <vector>

class Movie_list {
    private:
        std::vector<std::string> movies;

    public:
        Movie_list();
        void print_list();
        void add_movie(std::string movie);

};
#endif