#include "../header/User.hpp"

User::User(std::string user, std::string pass) {
    this->username = user;
    this->password = pass;
    //user constructor should import data from file
}

void User::load_movie_list() {

}

void User::load_review_list() {

}

Movie_List User::get_movie_list() {
    return watched_movies;
}

Review_List User::get_review_list() {
    return user_reviews;
}

std::string User::print_credentials() {
    return username + " " + password;
}