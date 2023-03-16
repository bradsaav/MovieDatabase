#include "../header/User.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

User::User(std::string user, std::string pass) {
    this->username = user;
    this->password = pass;
    load_movie_list();
}

User::User() {
    cout << "Enter new username and password:" << endl;
    cin >> this->username;
    cin >> this->password;
    cout << print_credentials() << endl;
}

void User::save_movie_list() {
    int i = 0;
    int j = 0;
    
    ofstream moviesFile;
    string path = "../data/" + username + "Movies.txt";
    cout << "Movies saving to: " << path << endl;
    moviesFile.open(path);

    moviesFile << password << endl;
    for (i = 0; i < watched_movies.get_size(); i++) {
        moviesFile << watched_movies.get_movie(i).get_name() << endl;
        moviesFile << watched_movies.get_movie(i).get_release_year() << endl;
        moviesFile << watched_movies.get_movie(i).get_rating() << endl;
        moviesFile << watched_movies.get_movie(i).get_genre().size() << endl;

        for (j = 0; j < watched_movies.get_movie(i).get_genre().size(); j++) {
            moviesFile << watched_movies.get_movie(i).get_genre().at(j) << endl;
        }

        moviesFile << watched_movies.get_movie(i).get_hour() << ' ' << watched_movies.get_movie(i).get_minute() << endl;
        moviesFile << watched_movies.get_movie(i).get_director().get_size() << endl;

        for (j = 0; j < watched_movies.get_movie(i).get_director().get_size(); j++) {
            moviesFile << watched_movies.get_movie(i).get_director().get_CastMember(j).get_name() << endl;
        }

        moviesFile << watched_movies.get_movie(i).get_cast().get_size() << endl;

        for (j = 0; j < watched_movies.get_movie(i).get_cast().get_size(); j++) {
            moviesFile << watched_movies.get_movie(i).get_cast().get_CastMember(j).get_name() << endl;
        }
    }

    cout << "Movies saved successfully" << endl;
    moviesFile.close();
}

void User::save_review_list() {

}

void User::load_movie_list() {
    string tempString = "";
    string path = "../data/" + username + "Movies.txt";
    int tempNum = 0;

    ifstream readMovieList;
    cout << "Opening user list at: " << path << endl;
    readMovieList.open(path);
    getline(readMovieList, tempString);
    if (tempString != password) {
        cout << "Password not equal" << endl;
        readMovieList.close();
        return;
    }
    
    while (getline(readMovieList, tempString)) {
        Movie m;
        m.set_name(tempString);

        readMovieList >> tempNum;
        m.set_year(tempNum);

        readMovieList.ignore(256, '\n');
        getline(readMovieList, tempString);
        m.set_rating(tempString);

        readMovieList >> tempNum;
        readMovieList.ignore(256, '\n');

        for (int i = 0; i < tempNum; i++) {
            getline(readMovieList, tempString);
            m.set_genre(tempString);
        }

        readMovieList >> tempNum;
        m.set_hour(tempNum);

        readMovieList >> tempNum;
        m.set_min(tempNum);
        readMovieList.ignore(256, '\n');

        readMovieList >> tempNum;
        readMovieList.ignore(256, '\n');

        for (int i = 0; i < tempNum; i++) {
            getline(readMovieList, tempString);
            m.set_director(tempString, 0);
        }

        readMovieList >> tempNum;
        readMovieList.ignore(256, '\n');

        for (int i = 0; i < tempNum; i++) {
            getline(readMovieList, tempString);
            m.set_cast(tempString, 0);
        }

        watched_movies.add_movie(m);
    }

    cout << "List loaded successfully" << endl;
    readMovieList.close();
}

void User::load_review_list() {

}

Movie_List & User::get_movie_list() {
    return watched_movies;
}

Review_List & User::get_review_list() {
    return user_reviews;
}

std::string User::print_credentials() {
    return username + " " + password;
}
