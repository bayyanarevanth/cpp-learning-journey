//
// Created by revanth on 30.11.25.
//

#include "MagicPet.hpp"

#include "MagicPet.hpp"
#include <iostream>
using namespace std;

const string MagicPet::def_name = "Unnamed MagicPet";
const int MagicPet::def_age = 0;


void MagicPet::doTrick()
{
    cout<<getName()<<" performs a magic trick!"<<endl;
}

void MagicPet::makesound()
{
    cout<<getName()<<" makes a mystical sound!"<<endl;
}
MagicPet::MagicPet(string newname, int newage):Pet(newname,newage){

}