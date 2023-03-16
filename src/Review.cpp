#include <iostream>
#include "../header/Review.hpp"
using namespace std;

Review::Review() {

}

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

int Review::get_score() {
    return score;
}

void Review::print_review() {
    cout << name << endl;
    cout << review << endl;
    cout << score << endl;
}

void Review::set_name(string n) {
    name = n;
}

void Review::set_review(string r) {
    review = r;
}

void Review::set_score(int i) {
    score = i;
}
