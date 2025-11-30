//
// Created by revanth on 30.11.25.
//

#ifndef CPP_PROJECT_MAGICPET_HPP
#define CPP_PROJECT_MAGICPET_HPP


#ifndef MAGIC_PET_HPP
#define MAGIC_PET_HPP

#include "Pet.hpp"
#include "SpecialAbility.hpp"

class MagicPet : public Pet, public SpecialAbility
{
private:
    static const string def_name;
    static const int def_age;
public:
    MagicPet(string newname=def_name, int newage=def_age);
    void makesound() override;
    void doTrick() override;
};



#endif



#endif //CPP_PROJECT_MAGICPET_HPP
