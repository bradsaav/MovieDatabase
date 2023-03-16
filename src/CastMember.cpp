#include "../header/CastMember.hpp"
#include <vector>
#include <string>

using namespace std;

CastMember::CastMember(string memberName, int memberAge) {
    name = memberName;
    age = memberAge;
}

string CastMember::get_name() {
    return name;
}

int CastMember::get_age() {
    return age;
}

vector <string> CastMember::get_movies() {
    return MovieList;
}

void CastMember::add_movie() {

}