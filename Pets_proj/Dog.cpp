//
// Created by revanth on 30.11.25.
//

#include "Dog.hpp"

#include <iostream>
using namespace std;

const string Dog::def_name = "Unnamed Dog";
const int Dog::def_age = 0;

void Dog::makesound()
{
    cout<<getName()<<" is barking! Woof!"<<endl;

}
Dog::Dog(string newname, int newage):Pet(newname,newage){
    ;
}