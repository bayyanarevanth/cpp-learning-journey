//
// Created by revanth on 21.11.25.
//


#include <iostream>
#include <string>

using namespace std;


void stringsAssignment(const string& s1)
{
    for (char c : s1)
    {
        string sp(s1.size()-1, ' ');
        cout << sp + c << endl;
    }



}