#include <iostream>
#include <fstream>
#include <string>
#include "../header/User.hpp"
#include "../header/Movie.hpp"

using namespace std;

int main() {
    //Creating new user
    /*User testUser;

    Movie testMovie;
    testMovie.set_name("TEST123");
    testMovie.set_year(1981);
    testMovie.set_rating("R");
    testMovie.set_hour(2);
    testMovie.set_min(20);
    testMovie.set_genre("Action");
    testMovie.set_director("Obama", 1);
    testMovie.set_cast("Romney", 1);
    testMovie.display_movie();

    cout << "Size: " << testUser.get_movie_list().get_size() << endl;
    testUser.get_movie_list().add_movie(testMovie);
    testUser.get_movie_list().add_movie(testMovie);
    cout << "Size After: " << testUser.get_movie_list().get_size() << endl;
    testUser.get_movie_list().get_movie(0).display_movie();

    testUser.save_movie_list();*/

    //Using existing user
    User testUser("test", "password");
    cout << "Size: " << testUser.get_movie_list().get_size() << endl;
    testUser.get_movie_list().get_movie(0).display_movie();
}
