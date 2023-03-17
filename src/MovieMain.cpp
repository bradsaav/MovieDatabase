#include <iostream>
#include <fstream>
#include <ctype.h>
#include "../header/MovieList.hpp"
#include "../header/DisplayRecommendations.hpp"
#include "../header/User.hpp"

using namespace std;
void user_add_Review (Review_List& reviews) {
    string reviewMovie;
    string reviewContent;
    int reviewScore;

    cout << "What is the name of the Movie you want to write a review for?" << endl;
    getline(cin, reviewMovie);

    cout << "Write the contents of the review." << endl;
    getline(cin, reviewContent);

    cout << "Enter a score from 1 - 5." << endl;
    cin >> reviewScore;
    cin.ignore(256, '\n');

    Review r(reviewMovie, reviewContent, reviewScore);
    reviews.add_review(r);
    
    cout << endl;
}

void user_add_Movie(Movie_List& movies) {
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
    char userNumber;
    cin >> userNumber;
    cin.ignore(256, '\n');

    while(!isdigit(userNumber)) {
        cout << userNumber << endl;
        cout << "Please enter valid number of genres in the Movie." << endl;
        cin >> userNumber;
        cin.ignore(256, '\n');
    }
    userNum = userNumber - '0';
    for (i = 0; i < userNum; i++) {
        cout << "Please enter one of the Movie's genres." << endl;
        getline(cin, userInput);
        m.set_genre(userInput);
    }

    cout << "Please enter the number of directors in the Movie." << endl;
    cin >> userNumber;
    cin.ignore(256, '\n');
    while(!isdigit(userNumber)) {
        cout << userNumber << endl;
        cout << "Please enter valid number of directors in the Movie." << endl;
        cin >> userNumber;
        cin.ignore(256, '\n');
    }
    userNum = userNumber - '0'; 
    for (i = 0; i < userNum; i++) {
        cout << "Please enter one of the Movie's directors." << endl;
        getline(cin, userInput);
        m.set_director(userInput, 0);
    }

    cout << "Please enter the number of starring cast in the Movie." << endl;
    cin >> userNumber;
    cin.ignore(256, '\n');
    while(!isdigit(userNumber)) {
        cout << userNumber << endl;
        cout << "Please enter valid number of starring cast in the Movie." << endl;
        cin >> userNumber;
        cin.ignore(256, '\n');
    }
    userNum = userNumber - '0'; 
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
    bool validInput = false;
    while(!validInput) {
        cout << "Type \'g\' for recommendation by genre" << endl;
        cout << "Type \'a\' for recommendation by actor" << endl;
        cout << "Type \'d\' for recommendation by director" << endl;
        cin >> userInput;
        cin.ignore(256, '\n');  
        if (userInput == "g") {
            validInput = true;
            string userGenre;
            cout << "What genre do you like?" << endl;
            cin >> userGenre;
            cin.ignore(256, '\n');
            cout << endl;
            DisplayRecommendations dr;
            dr.recommendByGenre(movies, userGenre);
        } else if (userInput == "a") {
            validInput = true;
            string userActor;
            cout << "Which actor/actress do you like?" << endl;
            getline(cin, userActor);
            cout << endl;
            DisplayRecommendations dr;
            dr.recommendByActor(movies, userActor);
        } else if (userInput == "d") {
            validInput = true;
            string userDirector;
            cout << "Which director do you like?" << endl;
            getline(cin, userDirector);
            cout << endl;
            DisplayRecommendations dr;
            dr.recommendByDirector(movies, userDirector);
        } else {
            cout << "Invalid recommendation input. Please input a valid option" << endl;
            continue;
    
        }
    }
}

void watchlist_options () {
    cout << "Type \'a\' to add a Movie to your watchlist." << endl;
    cout << "Type \'v\' to view all Movies." << endl;
    cout << "Type \'s\' to save watchlist." << endl;
    cout << "Type \'r\' to remove a movie from watchlist." << endl;
    cout << "Type \'l\' to load in movie list." << endl;
    cout << "Type \'e\' to exit back to menu." << endl;
    cout << endl;
}

void reviewlist_options () {
    cout << "Type \'a\' to add a review to your review list." << endl;
    cout << "Type \'v\' to view all reviews." << endl;
    cout << "Type \'s\' to save your review list." << endl;
    cout << "Type \'r\' to remove a review from your review list." << endl;
    cout << "Type \'l\' to load in review list." << endl;
    cout << "Type \'e\' to exit back to menu." << endl;
    cout << endl;
}

void display_options () {
    cout << "Type \'a\' to add a Movie to the DataBase." << endl;
    cout << "Type \'s\' to search for a specific Movie in the DataBase." << endl;
    cout << "Type \'r\' to recommend a Movie to you." << endl;
    cout << "Type \'c\' to create or load your review list." << endl;
    cout << "Type \'v\' to view all Movies." << endl;
    cout << "Type \'w\' to create or load a watchlist." << endl;
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

void display_all_reviews(Review_List& allReviews) {
    for (int i = 0; i < allReviews.get_size(); i++) {
        cout << i + 1 << '.' << endl;
        allReviews.get_review(i).print_review();
        cout << endl;
    }
}

void menu () {
    string userUsername = "";

    cout << "Enter username:" << endl;
    getline(cin, userUsername);

    User currUser(userUsername);

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
        } else if (userInput == "v") {
            display_all_movies(allMovies);
            display_options();
        } else if (userInput == "r") {
            recommendMovie(allMovies);
            display_options();
        } else if (userInput == "c") {
            reviewlist_options();
            cin >> userInput;
            cin.ignore(256, '\n');

            while (userInput != "e") {
                if (userInput == "a") {
                    user_add_Review(currUser.get_review_list());
                    userInput = "e";
                } else if (userInput == "v") {
                    display_all_reviews(currUser.get_review_list());
                    userInput = "e";
                } else if (userInput == "s") {
                    currUser.save_review_list();
                    userInput = "e";
                } else if (userInput == "r") {
                    string reviewName;
                    int reviewYear;

                    cout << "What is the name of the review?" << endl;
                    getline(cin, reviewName);
                    cout << endl;

                    currUser.get_review_list().remove_review(reviewName);
                    userInput = "e";
                } else if (userInput == "l") {
                    currUser.load_review_list();
                    userInput = "e";
                } else {
                    cout << "Invalid menu input. Please input a valid menu option" << endl;
                    watchlist_options();
                    cin >> userInput;
                    cin.ignore(256, '\n');
                    continue;
                }
            }
            display_options();
        } else if (userInput == "w") {
            watchlist_options();
            cin >> userInput;
            cin.ignore(256, '\n');

            while (userInput != "e") {
                if (userInput == "a") {
                    user_add_Movie(currUser.get_movie_list());
                    userInput = "e";
                } else if (userInput == "v") {
                    display_all_movies(currUser.get_movie_list());
                    userInput = "e";
                } else if (userInput == "s") {
                    currUser.save_movie_list();
                    userInput = "e";
                } else if (userInput == "r") {
                    string movieName;
                    int movieYear;

                    cout << "What is the name of the movie?" << endl;
                    getline(cin, movieName);

                    cout << "What is the release year of the movie?" << endl;
                    cin >> movieYear;
                    cin.ignore(256, '\n');

                    cout << endl;

                    currUser.get_movie_list().remove_movie(movieName, movieYear);
                    userInput = "e";
                } else if (userInput == "l") {
                    currUser.load_movie_list();
                    userInput = "e";
                } else {
                    cout << "Invalid menu input. Please input a valid menu option" << endl;
                    watchlist_options();
                    cin >> userInput;
                    cin.ignore(256, '\n');
                    continue;
                }
            }
            display_options();

        } else if (userInput == "s") {
            string movieName;
            int movieYear;

            cout << "What Movie are you looking for?" << endl;
            getline(cin, movieName);

            cout << "What is the Movie's release year?" << endl;
            cin >> movieYear;
            cin.ignore(256, '\n');

            cout << endl;

            allMovies.search(movieName, movieYear);

            cout << endl;

            display_options();
        } else {
            cout << "Invalid menu input. Please input a valid menu option" << endl;
            display_options();
            cin >> userInput;
            cin.ignore(256, '\n');
            continue;
        }

        cin >> userInput;
        cin.ignore(256, '\n');
    }
}

int main() {
    menu();
}