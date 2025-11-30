//
// Created by revanth on 30.11.25.
//

#ifndef CPP_PROJECT_PET_HPP
#define CPP_PROJECT_PET_HPP


#include <string>
using namespace std;

class Pet
{
private:
    static const string def_name;
    static const int def_age;
protected:
    string name;
    int age;
public:
    Pet(string initname, int initage);
    string getName();
    int getAge();
    void setName(string newName);
    void setAge(int newAge);
    void eat();
    virtual void makesound() =0;



};


#endif //CPP_PROJECT_PET_HPP
