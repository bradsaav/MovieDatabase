#include <iostream>
#include <fstream>
#include "../header/Movie_List.hpp"

using namespace std;

int main() {
    Movie_List allMovies;
    
    for (int i = 0; i < 15; i++) {
        Movie m;
        m.read_data();
        allMovies.add_movie(m);
    }

    for (int i = 0; i < allMovies.get_size(); i++) {
        cout << i + 1 << endl;
        allMovies.get_movie(i).display_movie();
        cout << endl;
    }
}
