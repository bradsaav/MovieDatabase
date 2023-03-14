#ifndef __MOVIE_LIST_HPP__
#define __MOVIE_LIST_HPP__

#include "Movie.hpp"

#include <vector>
#include <string>

class Movie_List {
    private:
        vector <Movie> movies;
        
    public:
        void add_movie(Movie m);
        Movie get_movie(int index);
        void remove_movie(string name, int year);
        int get_size();
        void create_MovieDB();
        void read_data();
};

#endif
