#include <iostream>
#include "../header/review.h"
using namespace std;

Review::Review(string n, string r, int s) {
    n = name;
    r = review;
    s = score;
}

string Review::getReview() {
    return review;
}

void Review::editReview(string r) {
    review = r;
        
}
string Review::getScore() {
    return score;
}
void Review::editScore(int s) {
    while(s < 1 || s > 5) {
        cout << "Please enter a score between 1 to 5." << endl;
    }
    score = s;
}