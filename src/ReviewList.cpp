#include "../header/ReviewList.hpp"

#include <vector>

using namespace std;

void ReviewList::add_Review(Review r) {
    reviews.push_back(r);
}

void ReviewList::remove_Review(string n, string r) {
    vector<Review>::iterator it;
    
 
    for (auto it = reviews.begin(); it != reviews.end(); ++it) {
        if (it->getName() == n && it->getReview() == r) {
            reviews.erase(it);
            return;
        }
    }
}

Review ReviewList::get_Review(int index) {
    return reviews.at(index);
}

int ReviewList::get_size() {
    return reviews.size();
}