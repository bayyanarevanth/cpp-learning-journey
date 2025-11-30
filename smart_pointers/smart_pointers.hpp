//
// Created by revanth on 30.11.25.
//
#include <vector>
#include <iostream>
#include <memory>


using namespace std;

#ifndef CPP_PROJECT_SMART_POINTERS_HPP
#define CPP_PROJECT_SMART_POINTERS_HPP


class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
};






#endif //CPP_PROJECT_SMART_POINTERS_HPP
