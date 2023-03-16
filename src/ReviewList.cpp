#include "../header/ReviewList.hpp"

#include <vector>
#include <string>

void Review_List::add_review(Review m) {
    reviews.push_back(m);
}

Review Review_List::get_review(int index) {
    return reviews.at(index);
}

void Review_List::remove_review(string name) {
    vector<Review>::iterator it;
 
    for (auto it = reviews.begin(); it != reviews.end(); ++it) {
        if (it->get_name() == name) {
            reviews.erase(it);
            return;
        }
    }
}

int Review_List::get_size() {
    return reviews.size();
}