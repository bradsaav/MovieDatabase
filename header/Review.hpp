#ifndef __REVIEW_HPP__
#define __REVIEW_HPP__
#include <iostream>
using namespace std;

class Review {
    private:
    string name;
    string review;
    int score;

    public:
    Review(string n, string r, int s);
    string get_name();
    string get_review();
    void editReview(string r);
    int getScore();
    void editScore(int s);
};
#endif