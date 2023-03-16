#include "../header/ReviewList.hpp"

#include <vector>
#include <string>
using namespace std;

void Review_List::add_review(Review m) {
    reviews.push_back(m);
}

Review Review_List::get_review(int index) {
    return reviews.at(index);
}

void Review_List::remove_Review(string n, string r) {
    vector<Review>::iterator it;
    
 
    for (auto it = reviews.begin(); it != reviews.end(); ++it) {
        if (it->getName() == n && it->getReview() == r) {
            reviews.erase(it);
            return;
        }
    }
}

int Review_List::get_size() {
  return reviews.size();
}

