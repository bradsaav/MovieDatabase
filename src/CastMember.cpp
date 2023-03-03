#include "../header/CastMember.hpp"
#include <list>
#include <string>
#include "../header/Movie_List.hpp"

using namespace std;

CastMember::CastMember(string memberName, int memberAge, Movie_List list) {
    name = memberName;
    age = memberAge;
    MovieList = list;
}

string CastMember::get_name() {
    return name;
}

int CastMember::get_age() {
    return age;
}

Movie_List CastMember::get_movies() {
    return MovieList;
}