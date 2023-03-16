#ifndef __CAST_LIST_HPP__
#define __CAST_LIST_HPP__


#include "CastMember.hpp"
#include <vector>

using namespace std;

class CastList {
	private: 
		vector <CastMember> castList;

	public:
		
		CastList();
		vector<CastMember> getCastList() const;
		void print_cast();
		void addCastMember(CastMember name);
		void deleteCastMember(string name);
		CastMember get_CastMember(int index);
		int get_size();

};

#endif



