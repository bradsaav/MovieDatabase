#include "../header/DisplayRecommendations.hpp"

#include <iostream>

using namespace std;

void DisplayRecommendations::recommendByGenre(Movie_List movies, string g) {
    Movie_List m;
    m = movies.searchGenre(g);

    for (int i = 0; i < m.get_size(); i++ ) {
        m.get_movie(i).display_movie();
        cout << endl;
    }

}

void DisplayRecommendations::recommendByActor(Movie_List movies, string a) {
    Movie_List m;
    m = movies.searchActor(a);

    for (int i = 0; i < m.get_size(); i++ ) {
        m.get_movie(i).display_movie();
        cout << endl;
    }
}

void DisplayRecommendations::recommendByDirector(Movie_List movies, string d) {
    Movie_List m;
    m = movies.searchDirector(d);

    for (int i = 0; i < m.get_size(); i++ ) {
        m.get_movie(i).display_movie();
        cout << endl;
    }
}