//
// Created by revanth on 14.11.25.
//
#include "../ObjectsAndClasses/Movies.hpp"
#include "../operator-overloading/operator-overload.hpp"

#ifndef CPP_PROJECT_ADDITIONAL_HPP
#define CPP_PROJECT_ADDITIONAL_HPP

using namespace std;
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, short int watched);

#endif //CPP_PROJECT_ADDITIONAL_HPP