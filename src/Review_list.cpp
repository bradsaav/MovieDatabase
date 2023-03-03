#include "../header/Review_list.hpp"

Review_list::Review_list() {

}

void Review_list::print_list() {
    for (std::string s: reviews) {
        std::cout << s << std::endl;
    }
}

void Review_list::add_review(std::string review) {
    reviews.push_back(review);
}