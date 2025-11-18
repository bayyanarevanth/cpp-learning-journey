//
// Created by revanth on 14.11.25.
//

#ifndef CPP_PROJECT_OPERATOROVERLOAD_HPP
#define CPP_PROJECT_OPERATOROVERLOAD_HPP
#include <string>
#include <cstring>
#include<iostream>
#include <string>
#include <numeric>
#include <ranges>


using namespace std;
class StringOperations
{

    friend std::ostream &operator<<(std::ostream &os, const StringOperations &rhs);
    friend std::istream &operator>>(std::istream &in, StringOperations &rhs);

private:
    char* strmem;
public:
    StringOperations()                  // constructor without initializing single member is not allowed
        : strmem(new char[1])           // initialize directly
    {                                   // you cannot give some value with nullptr allocation
        strmem[0] = '\0';
    }                                   // Default constructor
    StringOperations(const StringOperations& rhs);                          // Default Copy constructor
    StringOperations(StringOperations&& rhs) noexcept;                                         // Default move constructor
    StringOperations(const char *rhs);


    StringOperations& operator=(StringOperations&&) noexcept;                              // Default move assignment - Stealing the data
    StringOperations& operator=(const StringOperations&);               // Default assignment operator
    StringOperations operator-() const;
    StringOperations operator++() const;
    StringOperations operator+(const StringOperations&) const;
    StringOperations operator*(int) const;
    StringOperations& operator+=(const StringOperations&);
    int operator>(const StringOperations&) const;
    int operator<(const StringOperations&) const;
    bool operator!=(const StringOperations&) const;
    bool operator==(const StringOperations&) const;
    StringOperations& operator*=(int);

    [[nodiscard]] const char* get_membstring() const
    {
        return strmem;
    }
    ~StringOperations() {
        // std::cout << "Deleting: " << (void*)strmem << std::endl;
        delete[] strmem;
    }

};


#endif //CPP_PROJECT_OPERATOROVERLOAD_HPP