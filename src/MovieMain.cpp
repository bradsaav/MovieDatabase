#include <iostream>
#include <fstream>
#include "../header/MovieList.hpp"

using namespace std;

// void menu () {
//     Movie_List allMovies;

//     allMovies.read_data();    
//     allMovies.create_MovieDB();

//     string userInput = "q";

//     cin >> userInput;
//     cin.ignore(256, '\n');

//     while (userInput != "q") {
//         if () {

//         }
//     }
// }

void display_all_movies(Movie_List allMovies) {
    for (int i = 0; i < allMovies.get_size(); i++) {
        cout << i + 1 << '.' << endl;
        allMovies.get_movie(i).display_movie();
        cout << endl;
    }
}

int main() {
    Movie_List allMovies;

    allMovies.read_data();    

    // for (int i = 0; i < allMovies.get_size(); i++) {
    //     cout << i + 1 << '.' << endl;
    //     allMovies.get_movie(i).display_movie();
    //     cout << endl;
    // }

    allMovies.create_MovieDB();
}
