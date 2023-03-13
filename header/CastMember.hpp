#ifndef __CAST_MEMBER_HPP__
#define __CAST_MEMBER_HPP__

#include <vector>
#include <string>

using namespace std;

class CastMember {
    private: 
        string name;
        int age;
        vector <string> MovieList;

    public: 
        CastMember(string name, int age);
        string get_name();
        int get_age();
        vector <string> get_movies();
        void add_movie();
};

#endif
