#ifndef __CAST_LIST_HPP__
#define __CAST_LIST_HPP__


#include "CastMember.hpp"
#include <list>

class CastList {
	private: 
		list <CastMember> castList;

	public:
		void print_cast();
		void addCastMember(CastMember name);
		void deleteCastMember(string name);

};

#endif



