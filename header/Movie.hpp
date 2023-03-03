#ifndef __MOVIE_HPP__
#define __MOVIE_HPP__

#include <vector>
#include <string>

using namespace std;

class Movie {
    private:
        string name = "";
        int year = 0;
        string rating = "";
        vector <string> genre;
        int hour = 0;
        int min = 0;
        vector <string> producer;
        vector <string> cast;

    public:
        Movie(const string& name, int year, const string& rating, const vector <string>& genre, int hour, int min, const vector <string>& cast);
        Movie();
        string get_name();
        int get_release_year();
        vector <string> get_director() const;
        vector <string> get_cast() const;
        vector <string> get_genre() const;
        string get_duration();
        void read_data();
        void set_name(string n);
        void set_year(int t);
        void set_hour(int h);
        void set_min(int m);
        void set_genre(string g);
        void set_director(string d);
        void set_cast(string c);
        void display_cast();
        void display_movie();
        void display_duration();
        void display_genre();
};

#endif