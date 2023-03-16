#include "../header/MovieList.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void Movie_List::add_movie(Movie m) {
    movies.push_back(m);
}

int Movie_List::get_size() {
    return movies.size();
}

Movie Movie_List::get_movie(int index) {
    return movies.at(index);
}

void Movie_List::remove_movie(string name, int year) {
    vector<Movie>::iterator it;
 
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->get_name() == name && it->get_release_year() == year) {
            movies.erase(it);
            return;
        }
    }
}

void Movie_List::create_MovieDB() {
    int i = 0;
    int j = 0;
    
    ofstream moviesFile;

    moviesFile.open("../data/MovieDB.txt");

    if (!moviesFile.is_open()) {
        cout << "Failed to open and create MovieDB.txt" << endl;
        return;
    }

    for (i = 0; i < movies.size(); i++) {
        moviesFile << movies.at(i).get_name() << endl;
        moviesFile << movies.at(i).get_release_year() << endl;
        moviesFile << movies.at(i).get_rating() << endl;
        moviesFile << movies.at(i).get_genre().size() << endl;

        for (j = 0; j < movies.at(i).get_genre().size(); j++) {
            moviesFile << movies.at(i).get_genre().at(j) << endl;
        }

        moviesFile << movies.at(i).get_hour() << ' ' << movies.at(i).get_minute() << endl;
        moviesFile << movies.at(i).get_director().get_size() << endl;

        for (j = 0; j < movies.at(i).get_director().get_size(); j++) {
            moviesFile << movies.at(i).get_director().get_CastMember(j).get_name() << endl;
        }

        moviesFile << movies.at(i).get_cast().get_size() << endl;

        for (j = 0; j < movies.at(i).get_cast().get_size(); j++) {
            moviesFile << movies.at(i).get_cast().get_CastMember(j).get_name() << endl;
        }
    }

    moviesFile.close();
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

void Movie_List::read_data() {
    string tempString = "";
    int tempNum = 0;
    int i =0;

    ifstream readMovies;

    readMovies.open("../data/MovieDB.txt");

    if (!readMovies.is_open()) {
        cout << "failed to open data/MovieDB.txt" << endl;
        return;
    }
    
    while (getline(readMovies, tempString)) {
        Movie m;
        m.set_name(tempString);

        readMovies >> tempNum;
        m.set_year(tempNum);

        readMovies.ignore(256, '\n');
        getline(readMovies, tempString);
        m.set_rating(tempString);

        readMovies >> tempNum;
        readMovies.ignore(256, '\n');

        for (i = 0; i < tempNum; i++) {
            getline(readMovies, tempString);
            m.set_genre(tempString);
        }

        readMovies >> tempNum;
        m.set_hour(tempNum);

        readMovies >> tempNum;
        m.set_min(tempNum);
        readMovies.ignore(256, '\n');

        readMovies >> tempNum;
        readMovies.ignore(256, '\n');

        for (i = 0; i < tempNum; i++) {
            getline(readMovies, tempString);
            m.set_director(tempString, 0);
        }

        readMovies >> tempNum;
        readMovies.ignore(256, '\n');

        for (i = 0; i < tempNum; i++) {
            getline(readMovies, tempString);
            m.set_cast(tempString, 0);
        }

        movies.push_back(m);
    }

    readMovies.close();
}

Movie Movie_List::search(string name, int year) {
    int i = 0;
    
    for (i = 0; i < movies.size(); i++) {
        if (movies.at(i).get_name() == name && movies.at(i).get_release_year() == year) {
            return movies.at(i);
        }
    }
}

Movie_List Movie_List::searchGenre(string g) {
    Movie_List m;

    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < movies.at(i).get_genre().size(); j++) {
            if (movies.at(i).get_genre().at(j) == g) {
                m.add_movie(movies.at(i));
            }
        }
    }

    return m;
}

Movie_List Movie_List::searchDirector(string d) {
    Movie_List m;

    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < movies.at(i).get_director().get_size(); j++) {
            if (movies.at(i).get_director().get_CastMember(j).get_name() == d) {
                m.add_movie(movies.at(i));
            }
        }
    }

    return m;
}

Movie_List Movie_List::searchActor(string a) {
    Movie_List m;

    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < movies.at(i).get_cast().get_size(); j++) {
            if (movies.at(i).get_cast().get_CastMember(j).get_name() == a) {
                m.add_movie(movies.at(i));
            }
        }
    }

    return m;
}