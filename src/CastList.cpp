#include "../header/CastList.hpp"
#include <list>
#include <string>
#include <iostream>

using namespace std;

void CastList::print_cast() {
    list <CastMember>::iterator it;

    for (it = castList.begin(); it != castList.end(); ++it) {
        string name = it->get_name();
        cout << name << endl;
    }
}

void CastList::addCastMember(CastMember name) {
    castList.push_back(name);
}

void CastList::deleteCastMember(string name) {
    list<CastMember>::iterator it;
    for (it = castList.begin(); it != castList.end(); ++it) {
        string cast = it->get_name();
        if (cast == name) {
            castList.erase(it);
        }
    }
}