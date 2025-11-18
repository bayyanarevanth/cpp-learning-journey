//
// Created by revanth on 14.11.25.
//

#include "additional.hpp"


void add_movie(Movies &movies, std::string name, std::string rating, short int watched) {
    if (movies.add_movie(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
        movies.display_all_movies();
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}