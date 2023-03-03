#ifndef REVIEW_H
#define REVIEW_H
#include <iostream>
using namespace std;

class Review {
    private:
    string name;
    string review;
    int score;


    public:
    Review(string n, string r, int s);
    string getReview();
    void editReview(string r);
    int getScore();
    void editScore(int s);
};
#endif