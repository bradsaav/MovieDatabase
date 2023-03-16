#include "../header/CastList.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

CastList::CastList() {
    castList = {};
}

vector<CastMember> CastList::getCastList() const {
    return castList;
}

void CastList::print_cast() {
    vector <CastMember>::iterator it;

    for (it = castList.begin(); it != castList.end(); ++it) {
        string name = it->get_name();
        cout << name << endl;
    }
}

void CastList::addCastMember(CastMember name) {
    castList.push_back(name);
}

void CastList::deleteCastMember(string name) {
    vector<CastMember>::iterator it;
    for (it = castList.begin(); it != castList.end(); ++it) {
        string cast = it->get_name();
        if (cast == name) {
            castList.erase(it);
        }
    }
}

CastMember CastList::get_CastMember(int index) {
    return castList.at(index);
}



int CastList::get_size() {
    return castList.size();
}