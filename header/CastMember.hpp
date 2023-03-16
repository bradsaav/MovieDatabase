#ifndef __CAST_MEMBER_HPP__
#define __CAST_MEMBER_HPP__

#include <vector>
#include <string>

using namespace std;

class CastMember {
    private: 
        string name;
        int age;

    public: 
        CastMember(string name, int age);
        string get_name();
        int get_age();
};

#endif
