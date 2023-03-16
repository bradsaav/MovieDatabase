#ifndef _RECOMMENDATIONS_HPP__
#define _RECOMMENDATIONS_HPP__

#include "MovieList.hpp"

class DisplayRecommendations {

    public:
        void recommendByGenre(Movie_List movies, string g);
        void recommendByActor(Movie_List movies, string a);
        void recommendByDirector(Movie_List movies, string d);
};
#endif