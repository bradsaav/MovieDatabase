#ifndef __CAST_MEMBER_HPP__
#define __CAST_MEMBER_HPP__

#include <list>
#include <string>
#include "../header/Movie_List.hpp"
using namespace std;

class CastMember {
    private: 
        string name;
        int age;
        Movie_List MovieList;
        bool isDirector;

    public: 
        CastMember(string name, int age, Movie_List list);
        string get_name();
        int get_age();
        Movie_List get_movies();
};

#endif
