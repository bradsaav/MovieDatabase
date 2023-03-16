#include <iostream>
#include "../header/Review.hpp"
using namespace std;

Review::Review(string n, string r, int s) {
   name = n;
   review = r;
   score = s;
}

string Review::get_name() {
    return name;
}

string Review::get_review() {
    return review;
}

void Review::editReview(string r) {
    review = r;
        
}
int Review::getScore() {
    return score;
}

void Review::editScore(int s) {
    while(s < 1 || s > 5) {
        cout << "Please enter a score between 1 to 5." << endl;
    }
    score = s;
}