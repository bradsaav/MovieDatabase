#ifndef REVIEWLIST_HPP
#define REVIEWLIST_HPP

#include "../header/Review.h"

#include <vector>

using namespace std;

class ReviewList {
    private:
        vector <Review> reviews;

    public:
        void add_Review(Review r);
        void remove_Review(string n, string r);
        Review get_Review(int index);
        int get_size();
};

#endif