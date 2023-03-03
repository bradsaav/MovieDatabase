#include "../header/Movie.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Movie::Movie(const string& name, int year, const string& rating, const vector <string>& genre, int hour, int min, const vector <string>& cast) {
    this->name = name;
    this->year = year;
    this->rating = rating;
    this->genre = genre;
    this->cast = cast;
}

Movie::Movie() {
    string name = "";
    int year = 0;
    string rating = "";
    int hour = 0;
    int min = 0;
}

string Movie::get_name() {
    return name;
}

int Movie::get_release_year() {
    return year;
}

vector <string> Movie::get_director() const{
    return producer;
}

vector <string> Movie::get_cast() const{
    return cast;
}

vector <string> Movie::get_genre() const{
    return genre;
}

void Movie::set_name(string n) {
    name = n;
}

void Movie::set_year(int y) {
    year = y;
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

void Movie::set_director(string d) {
    producer.push_back(d);
}

void Movie::set_cast(string c) {
    cast.push_back(c);
}

// movie
// year
// rating
// number in category
// genre
// duration: hour minute
// number in category
// director
// number in category
// cast

void Movie::read_data() {
    string tempString = "";
    int tempNum = 0;
    int i =0;

    getline(cin, name);
    cin >> year;
    cin.ignore(256, '\n');
    getline(cin, rating);

    cin >> tempNum;
    cin.ignore(256, '\n');

    for (i = 0; i < tempNum; i++) {
        getline(cin, tempString);
        genre.push_back(tempString);
    }

    cin >> hour;
    cin >> min;
    cin.ignore(256, '\n');

    cin >> tempNum;
    cin.ignore(256, '\n');

    for (i = 0; i < tempNum; i++) {
        getline(cin, tempString);
        producer.push_back(tempString);
    }

    cin >> tempNum;
    cin.ignore(256, '\n');

    for (i = 0; i < tempNum; i++) {
        getline(cin, tempString);
        cast.push_back(tempString);
    }

}

void Movie::display_movie() {
    cout << get_name() << endl;
    cout << get_release_year() << endl;
    display_genre();
    display_duration();
    display_cast();
}

void Movie::display_cast() {
    int i = 0;

    cout << "Director(s): ";

    for (i = 0; i < producer.size(); ++i) {
        if (i == producer.size() - 1) {
            cout << producer.at(i) << endl;
        }
        else {
            cout << producer.at(i) << " - ";
        }
    }

    cout << "Starring: ";

    for (i = 0; i < cast.size(); ++i) {
        if (i == cast.size() - 1) {
            cout << cast.at(i) << endl;
        }
        else {
            cout << cast.at(i) << " - ";
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