#include "../header/User.hpp"

User::User(std::string user, std::string pass) {
    this->username = user;
    this->password = pass;
}

Movie_list User::get_movie_list() {
    return watched_movies;
}

Review_list User::get_reviews() {
    return user_reviews;
}
void User::print_stats() {
    watched_movies.print_list();
}
void User::get_recommendations() {
    std::cout << "NOT IMPLEMENTED YET" << std::endl;
}
std::string User::print_credentials() {
    return username + " " + password;
}