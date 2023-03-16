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
    Review();
    Review(string n, string r, int s);
    string get_name();
    string get_review();
    void edit_review(string r);
    int get_score();
    void edit_score(int s);
    void print_review();
    void set_name(string n);
    void set_review(string r);
    void set_score(int i);
};
#endif