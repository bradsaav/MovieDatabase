#ifndef REVIEW_H
#define REVIEW_H

class Review {
    private:
    string name;
    string review;
    int score;


    public:
    string getReview() {
        return review;
    }
    void setReview(string r) {
        review = r;
        
    }
    string getScore() {
        return score;
    }
    void setScore(int s) {
        while(s < 1 || s > 5) {
            cout << "Please enter a score between 1 to 5." << endl;
        }
        score = s;
    }


};
#endif