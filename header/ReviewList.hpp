
#ifndef __REVIEW_LIST_HPP__
#define __REVIEW_LIST_HPP__

#include "Review.hpp"

#include <vector>
#include <string>

class Review_List {
    private:
        vector <Review> reviews;
        
    public:
        void add_review(Review m);
        Review get_review(int index);
        void remove_review(string n, string r);
        int get_size();
};

#endif
