//
// Created by revanth on 30.11.25.
//

#include "Pet.hpp"

#include <iostream>

using namespace std;

const string Pet::def_name = "Unnamed Dog";
const int Pet::def_age = 0;

string Pet::getName()
{
    return name;
}
int Pet::getAge()
{
    return age;
}
void Pet::setName(string newName){
    name = newName;
}
void Pet::setAge(int newAge){
    age = newAge;
}


void Pet::eat(){
    cout<< name <<" is eating!"<<endl;
}

Pet::Pet(string initname=def_name, int initage=def_age):name{initname},age{initage}{

}


