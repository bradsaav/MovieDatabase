#include "../header/User.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

User::User(std::string user) {
    this->username = user;
}

void User::save_movie_list() {
    int i = 0;
    int j = 0;
    
    ofstream moviesFile;
    string path = "../data/" + username + "Movies.txt";
    cout << "Movies saving to: " << path << endl;
    moviesFile.open(path);

    if (!moviesFile.is_open()) {
        cout << "Username does not exist or match." << endl;
        return;
    }

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
    ofstream reviewsFile;
    string path = "../data/" + username + "Reviews.txt";
    cout << "Reviews saving to: " << path << endl;
    reviewsFile.open(path);

    if (!reviewsFile.is_open()) {
        cout << "Username does not exist or match." << endl;
        return;
    }

    for (int i = 0; i < user_reviews.get_size(); i++) {
        reviewsFile << user_reviews.get_review(i).get_name() << endl;
        reviewsFile << user_reviews.get_review(i).get_review() << endl;
        reviewsFile << user_reviews.get_review(i).get_score() << endl;
    }
    cout << "Reviews saved successfully" << endl;
    reviewsFile.close();
}

void User::load_movie_list() {
    watched_movies.movie_clear();
    string tempString = "";
    string path = "../data/" + username + "Movies.txt";
    int tempNum = 0;

    ifstream readMovieList;
    cout << "Opening user list at: " << path << endl;
    readMovieList.open(path);

    if (!readMovieList.is_open()) {
        cout << "Username does not exist or match." << endl;
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
    user_reviews.review_clear();
    string tempString = "";
    string path = "../data/" + username + "Reviews.txt";
    int tempNum = 0;

    ifstream readReviewList;
    cout << "Opening user list at: " << path << endl;
    readReviewList.open(path);

    if (!readReviewList.is_open()) {
        cout << "Username does not exist or match." << endl;
        return;
    }

    while (getline(readReviewList, tempString)) {
        Review r;
        r.set_name(tempString);
        getline(readReviewList, tempString);
        r.set_review(tempString);
        readReviewList >> tempNum;
        r.set_score(tempNum);
        user_reviews.add_review(r);
    }
}

Movie_List & User::get_movie_list() {
    return watched_movies;
}

Review_List & User::get_review_list() {
    return user_reviews;
}
