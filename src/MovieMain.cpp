#include <iostream>
#include <fstream>
#include "../header/MovieList.hpp"
#include "../header/DisplayRecommendations.hpp"

using namespace std;

void user_add_Movie (Movie_List& movies) {
    Movie m;
    string userInput;
    int userNum;
    int i = 0;

    cout << "Please enter the Movie's title." << endl;
    getline(cin, userInput);
    m.set_name(userInput);

    cout << "Please enter the Movie's release year." << endl;
    cin >> userNum;
    cin.ignore(256, '\n');
    m.set_year(userNum);

    cout << "Please enter the Movie's rating." << endl;
    getline(cin, userInput);
    m.set_rating(userInput);

    cout << "Please enter the Movie's hours." << endl;
    cin >> userNum;
    cin.ignore(256, '\n');
    m.set_hour(userNum);

    cout << "Please enter the Movie's minutes." << endl;
    cin >> userNum;
    cin.ignore(256, '\n');
    m.set_min(userNum);

    cout << "Please enter the number of genres in the Movie." << endl;
    cin >> userNum;
    cin.ignore(256, '\n');
    
    for (i = 0; i < userNum; i++) {
        cout << "Please enter one of the Movie's genres." << endl;
        getline(cin, userInput);
        m.set_genre(userInput);
    }

    cout << "Please enter the number of directors in the Movie." << endl;
    cin >> userNum;
    cin.ignore(256, '\n');
    
    for (i = 0; i < userNum; i++) {
        cout << "Please enter one of the Movie's directors." << endl;
        getline(cin, userInput);
        m.set_director(userInput, 0);
    }

    cout << "Please enter the number of starring cast in the Movie." << endl;
    cin >> userNum;
    cin.ignore(256, '\n');
    
    for (i = 0; i < userNum; i++) {
        cout << "Please enter one of the Movie's actors/actresses." << endl;
        getline(cin, userInput);
        m.set_cast(userInput, 0);
    }

    movies.add_movie(m);

    cout << endl;
}

void recommendMovie(Movie_List& movies) {
    string userInput;

    cout << "Type \'g\' for recommendation by genre" << endl;
    cout << "Type \'a\' for recommendation by actor" << endl;
    cout << "Type \'d\' for recommendation by director" << endl;

    cin >> userInput;
    cin.ignore(256, '\n');

    if (userInput == "g") {
        string userGenre;
        cout << "What genre do you like?" << endl;
        cin >> userGenre;
        cin.ignore(256, '\n');
        cout << endl;
        DisplayRecommendations dr;
        dr.recommendByGenre(movies, userGenre);

    }
    if (userInput == "a") {
        string userActor;
        cout << "Which actor/actress do you like?" << endl;
        getline(cin, userActor);
        cout << endl;
        DisplayRecommendations dr;
        dr.recommendByActor(movies, userActor);
    }
    if (userInput == "d") {
        string userDirector;
        cout << "Which director do you like?" << endl;
        getline(cin, userDirector);
        cout << endl;
        DisplayRecommendations dr;
        dr.recommendByDirector(movies, userDirector);
    }
}

void display_options () {
    cout << "Type \'a\' to add a Movie to the DataBase." << endl;
    cout << "Type \'s\' to search for a specific Movie in the DataBase." << endl;
    cout << "Type \'r\' to recommend a Movie to you." << endl;
    cout << "Type \'v\' to view all Movies." << endl;
    cout << "Type \'q\' to exit the program." << endl;
    cout << endl;
}

void display_all_movies(Movie_List& allMovies) {
    for (int i = 0; i < allMovies.get_size(); i++) {
        cout << i + 1 << '.' << endl;
        allMovies.get_movie(i).display_movie();
        cout << endl;
    }
}

void menu () {
    Movie_List allMovies;

    allMovies.read_data();
    display_options();

    string userInput = "q";

    cin >> userInput;
    cin.ignore(256, '\n');

    while (userInput != "q") {
        if (userInput == "a") {
            user_add_Movie(allMovies);
            cout << endl;
            allMovies.create_MovieDB();
            display_options();
        }

        if (userInput == "v") {
            display_all_movies(allMovies);
            display_options();
        }

        if (userInput == "r") {
            recommendMovie(allMovies);
            display_options();
        }

        if (userInput == "s") {
            string userMovie;
            int userYear;

            cout << "What Movie are you looking for?" << endl;
            cin >> userMovie;

            cout << "What is the Movie's release year?" << endl;
            cin >> userYear;

            cout << endl;

            allMovies.search(userMovie, userYear);
            display_options();
        }

        cin >> userInput;
    }
}

int main() {
    menu();
}
