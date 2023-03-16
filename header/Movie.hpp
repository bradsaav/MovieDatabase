#ifndef __MOVIE_HPP__
#define __MOVIE_HPP__

#include "CastList.hpp"
#include "ReviewList.hpp"

#include <vector>
#include <string>

using namespace std;

class Movie {
    private:
        string name;
        int year;
        string rating;
        vector <string> genre;
        int hour;
        int min;
        CastList producer;
        CastList cast;
        ReviewList reviews;
        double score = 0;

    public:
        Movie();
        string get_name();
        int get_release_year();
        string get_rating();
        CastList get_director() const;
        CastList get_cast() const;
        vector <string> get_genre() const;
        int get_hour() const;
        int get_minute() const;
        double get_score();
        ReviewList get_reviews();
        double calculate_score();
        void set_name(string n);
        void set_year(int t);
        void set_rating(string r);
        void set_hour(int h);
        void set_min(int m);
        void set_genre(string g);
        void set_director(string n, int a);
        void set_cast(string n, int a);
        void display_cast();
        void display_movie();
        void display_duration();
        void display_genre();
        void display_reviews();
};

#endif