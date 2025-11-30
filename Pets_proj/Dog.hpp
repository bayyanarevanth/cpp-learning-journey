//
// Created by revanth on 30.11.25.
//

#ifndef CPP_PROJECT_DOG_HPP
#define CPP_PROJECT_DOG_HPP


#ifndef DOG_HPP
#define DOG_HPP

#include "Pet.hpp"

class Dog:public Pet
{
private:
    static const string def_name;
    static const int def_age;
public:
    Dog(string newname=def_name, int newage=def_age);
    void makesound() override;

};



#endif


#endif //CPP_PROJECT_DOG_HPP
