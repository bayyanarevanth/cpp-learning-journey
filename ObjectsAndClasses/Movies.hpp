//
// Created by revanth on 13.11.25.
//
#include <iostream>
#ifndef CPP_PROJECT_MOVIES_HPP
#define CPP_PROJECT_MOVIES_HPP
#include <vector>
#include "Movie.hpp"

using namespace std;
class Movies
{
    private:
        vector<Movie> movie;
        static int movie_count;
    public:
        bool add_movie(string name, string rating, short int watched)
        {
            bool retval = true;
            for (Movie &m : movie)
            {
                if (m.get_moviename() == name)
                {
                    retval = false;
                    break;
                }
            }
            if (retval == true)
                movie.emplace_back(name,rating,watched);
            return retval;
        }
        bool increment_watched(string &name)
        {
            bool retval = false;
            for (Movie &m : movie)
            {
                if (m.get_moviename() == name)
                {
                    retval = true;
                    m.increment_watchedcnt();
                    break;
                }
            }
            return retval;
        }
         bool increment_watched(string &&name)
        {
            bool retval = false;
            for (Movie &m : movie)
            {
                if (m.get_moviename() == name)
                {
                    retval = true;
                    m.increment_watchedcnt();
                    break;
                }
            }
            return retval;
        }       
        void display_all_movies()
        {
            if (movie.size() == 0)
                cout<< "Sorry, there is no Movie to Display"<<endl;
            else
            {
                cout<<endl<< "================================================ "<<endl;
                cout<< "Movie Name: Movie Rating : Movie Watched Count"<<endl;
                for (Movie &m : movie)
                    cout << m.get_moviename() << ": " << m.get_movierating() << ": " << m.get_movieWatchedCnt() << endl;
                
                cout<< "================================================ "<<endl<<endl;
            }
        }
        Movies()
        {
            //cout<<"Object construction";
        };
        ~Movies()
        {
            //cout<<"Object destruction";
        };
};



#endif //CPP_PROJECT_MOVIES_HPP