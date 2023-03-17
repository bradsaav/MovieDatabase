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

void Review_List::remove_review(string n, string r) {
    vector<Review>::iterator it;
    
 
    for (auto it = reviews.begin(); it != reviews.end(); ++it) {
        if (it->get_name() == n && it->get_review() == r) {
            reviews.erase(it);
            return;
        }
    }
}

int Review_List::get_size() {
  return reviews.size();
}

