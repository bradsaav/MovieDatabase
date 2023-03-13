#include "../header/Movie.hpp"

#include <vector>
#include <string>
#include <iostream>

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

CastList Movie::get_director() const{
    return producer;
}

CastList Movie::get_cast() const{
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

void Movie::set_director(string n, int a) {
    CastMember d(n, a);
    producer.addCastMember(d);
}

void Movie::set_cast(string n, int a) {
    CastMember c(n, a);
    cast.addCastMember(c);
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
        set_director(tempString, 0);
    }

    cin >> tempNum;
    cin.ignore(256, '\n');

    for (i = 0; i < tempNum; i++) {
        getline(cin, tempString);
        set_cast(tempString, 0);
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