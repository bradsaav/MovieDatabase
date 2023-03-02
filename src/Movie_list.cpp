#include "../header/Movie_list.hpp"

Movie_list::Movie_list() {

}

void Movie_list::print_list() {
    for (std::string s: movies) {
        std::cout << s << std::endl;
    }
}

void Movie_list::add_movie(std::string movie) {
    movies.push_back(movie);
}