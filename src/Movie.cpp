#include "../header/Movie.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Movie::Movie() {
    name = "";
    year = 0;
    rating = "";
    hour = 0;
    min = 0;
}

string Movie::get_name() {
    return name;
}

int Movie::get_release_year() {
    return year;
}

string Movie::get_rating() {
    return rating;
}

CastList Movie::get_director() const{
    return producer;
}

CastList Movie::get_cast() const{
    return cast;
}

vector <string> Movie::get_genre() const{
    return genre;
}

int Movie::get_hour() const {
    return hour;
}

int Movie::get_minute() const {
    return min;
}

void Movie::set_name(string n) {
    name = n;
}

void Movie::set_year(int y) {
    year = y;
}

void Movie::set_rating(string r) {
    rating = r;
}

void Movie::set_hour(int h) {
    hour = h;
}

void Movie::set_min(int m) {
    min = m;
}

void Movie::set_genre(string g) {
    genre.push_back(g);
}

void Movie::set_director(string n, int a) {
    CastMember d(n, a);
    producer.addCastMember(d);
}

void Movie::set_cast(string n, int a) {
    CastMember c(n, a);
    cast.addCastMember(c);
}

void Movie::display_movie() {
    cout << get_name() << endl;
    cout << get_release_year() << endl;
    cout << get_rating() << endl;
    display_genre();
    display_duration();
    display_cast();
}

void Movie::display_cast() {
    int i = 0;

    cout << "Director(s): ";

    for (i = 0; i < producer.get_size(); ++i) {
        if (i == producer.get_size() - 1) {
            cout << producer.get_CastMember(i).get_name() << endl;
        }
        else {
            cout << producer.get_CastMember(i).get_name() << " - ";
        }
    }

    cout << "Starring: ";

    for (i = 0; i < cast.get_size(); ++i) {
        if (i == cast.get_size() - 1) {
            cout << cast.get_CastMember(i).get_name() << endl;
        }
        else {
            cout << cast.get_CastMember(i).get_name() << " - ";
        }
    }

}

void Movie::display_duration() {
    cout << hour << "h " << min << 'm' << endl;
}

void Movie::display_genre() {
    int i = 0;

    cout << "Genre(s): ";

    for (i = 0; i < genre.size(); ++i) {
        if (i == genre.size() - 1) {
            cout << genre.at(i) << endl;
        }
        else {
            cout << genre.at(i) << " - ";
        }
    }
}