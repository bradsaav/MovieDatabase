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
    Review();
    string getReview();
    void setReview(string r);
    string getScore();
    void setScore(int s);
};
#endif