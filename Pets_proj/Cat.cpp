//
// Created by revanth on 30.11.25.
//

#include "Cat.hpp"

#include "Cat.hpp"
#include <iostream>
using namespace std;

const string Cat::def_name = "Unnamed Cat";
const int Cat::def_age = 0;

void Cat::makesound()
{
    cout<<getName()<<" is meowing! Meow!"<<endl;

}

Cat::Cat(string newname, int newage):Pet(newname,newage){

}