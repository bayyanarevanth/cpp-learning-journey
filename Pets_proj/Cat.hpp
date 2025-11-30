//
// Created by revanth on 30.11.25.
//

#ifndef CPP_PROJECT_CAT_HPP
#define CPP_PROJECT_CAT_HPP


#ifndef CAT_HPP
#define CAT_HPP

#include "Pet.hpp"

class Cat: public Pet {
private:
    static const string def_name;
    static const int def_age;
public:
    Cat(string newname=def_name, int newage=def_age);
    virtual void makesound() override;
};

#endif


#endif //CPP_PROJECT_CAT_HPP
