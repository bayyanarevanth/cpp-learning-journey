//
// Created by revanth on 12.11.25.
//
#include<iostream>
#ifndef CPP_PROJECT_SECTION13_CHALLENGE_H
#define CPP_PROJECT_SECTION13_CHALLENGE_H


#include <string>

using namespace std;

class Movie
{
private:
    string Moviename;
    string MovieRating;
    short int MovieWatchedCnt = 0;
public:
    // Constructor
    Movie(string Moviename,string MovieRating, short int MovieWatchedCnt):
    Moviename{Moviename}, MovieRating(MovieRating), MovieWatchedCnt{MovieWatchedCnt}
    {

    }
    Movie(Movie &&movie) : Moviename{movie.Moviename}, MovieRating{movie.MovieRating}, MovieWatchedCnt{movie.MovieWatchedCnt}
    {
        //cout<<"Move constructor called"<<endl;
    }
    // Copy constructor
    Movie(const Movie &movie): Moviename{movie.Moviename}, MovieRating{movie.MovieRating}, MovieWatchedCnt{movie.MovieWatchedCnt}
    {
        //cout<<"Copy constructor called"<<endl;
    }
    ~Movie()
    {
        //cout<<"~Movie(): Destructor called"<<endl;
    }
    string get_moviename()
    {
        return Moviename;
    }
    short int get_movieWatchedCnt()
    {
        return MovieWatchedCnt;
    }
    string get_movierating()
    {
        return MovieRating;
    }
    void increment_watchedcnt()
    {
        MovieWatchedCnt++;
    }

};







#endif //CPP_PROJECT_SECTION13_CHALLENGE_H