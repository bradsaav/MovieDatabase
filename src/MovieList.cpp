#include "../header/MovieList.hpp"

#include <vector>
#include <string>

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
