#include <iostream>
#include "../header/review.h"

using namespace std;

int main() {
    Review aReview("George", "Bad Movie!", 2);
    cout << aReview.getReview() << " Score: " << aReview.getScore() << endl;
    aReview.editReview("Amazing Movie!");
    aReview.editScore(5);
    cout << aReview.getReview() << " Score: " << aReview.getScore() << endl;

    return 0; 
}
