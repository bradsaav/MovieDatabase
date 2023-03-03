#ifndef REVIEW_LIST_H
#define REVIEW_LIST_H

#include <string>
#include <iostream>
#include <vector>

class Review_list {
    private:
        std::vector<std::string> reviews;

    public:
        Review_list();
        void print_list();
        void add_review(std::string review);
};
#endif