#include <iostream>
#include <fstream>
#include "../header/MovieList.hpp"

using namespace std;

int main() {
    Movie_List allMovies;
    
    allMovies.read_data();

    for (int i = 0; i < allMovies.get_size(); i++) {
        cout << i + 1 << '.' << endl;
        allMovies.get_movie(i).display_movie();
        cout << endl;
    }

    allMovies.create_MovieDB();
}
