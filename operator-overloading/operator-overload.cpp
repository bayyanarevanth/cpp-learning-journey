//
// Created by revanth on 14.11.25.
/*
 *Pointers in this file at
 *  operator=(const StringOperations& rhs)
 *  operator=(StringOperations&& str) noexcept
 *  operator+
 *  operator*
*/
//

#include "operator-overload.hpp"



using namespace std;


StringOperations::StringOperations(const StringOperations& rhs)                             // Copy Constructor
{
    strmem = new char[std::strlen(rhs.strmem) + 1];
    strcpy(strmem,rhs.strmem);
}

StringOperations::StringOperations(StringOperations&& rhs) noexcept : strmem{rhs.strmem}    //Move constructor
{
    rhs.strmem = nullptr;
}

StringOperations& StringOperations::operator=(const StringOperations& rhs)                  // Copy assignment operator
{
    if (this != &rhs)
    {
        delete[] strmem;
        strmem = new char[std::strlen(rhs.strmem) + 1];
        strcpy (strmem,rhs.strmem);
    }
    return *this;
}

/* buggy old code           // Copy assignment operator
    StringOperations& StringOperations::operator=(const StringOperations& rhs) {
    strmem = new char[std::strlen(rhs.strmem) + 1];   // Allready allocated memory for strmem will still be present
                                                      // therefore memory leak happens, corrupted heap is later
                                                      // opearatoins
    strcpy(strmem, rhs.strmem);
    return *this;
    }                                                 // First self assignment check has to be done for "opeartor="
*/

StringOperations& StringOperations::operator=(StringOperations&& str) noexcept              // Move Assignment operator
{
    if (this != &str)
    {
        delete[] strmem;                    // free current buffer
        strmem = str.strmem;                // steal pointer
        str.strmem = nullptr;               // prevent double delete
    }
    return *this;
}

/* buggy old code  // Move Assignment operator
    StringOperations& StringOperations::operator=(StringOperations&& str) noexcept {
    delete[] strmem;                    // Deleting the memory
    strcpy(strmem, str.strmem);         // writing with strcpy on freed memory : heap corruption
    str.strmem = nullptr;
    return *this;
    }                                   // First self assignment check has to be done for "opeartor="
*/

StringOperations::StringOperations(const char* rhs)                                         // C-string constructor
{
    // std::cout << "Constructing: " << (void*)rhs << std::endl;
    if (rhs==nullptr) {
        strmem = new char[1];
        strmem[0] = '\0';
    } else {
        size_t len = strlen(rhs) +1;
        strmem = new char[len];
        strcpy(strmem, rhs);
    }
}

std::ostream &operator<<(std::ostream &os, const StringOperations &rhs)                    // overloaded insertion operator
{
    os << rhs.get_membstring();
    return os;
}


std::istream &operator>>(std::istream &in, StringOperations &rhs)
{
    std::string temp;
    in >> temp;
    rhs = StringOperations{temp.c_str()};
    return in;
}


// StringOperations::StringOperations(string& str)
// {
//     this->set_membstring(str);
// }


StringOperations StringOperations::operator-() const
{
    char* buff= new char[std::strlen(this->strmem) + 1];
    std::strcpy(buff, strmem);
    for (size_t i=0; i<std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    

    StringOperations temp {buff};
    delete [] buff;
    return temp;
}

StringOperations& StringOperations::operator++()
{
    for (size_t i=0; i< std::strlen(strmem); i++)
        strmem[i] = std::toupper(strmem[i]);
    return *this;
}

StringOperations StringOperations::operator+(const StringOperations& rhs) const
{
    const size_t len = strlen(this->strmem) + strlen(rhs.strmem);
    char* buff = new char[len+1];
    strcpy(buff, this->strmem);
    strcat(buff, rhs.strmem);
    StringOperations temp {buff};
    delete [] buff;
    return temp;
}


// Buggy code
// StringOperations StringOperations::operator+(const StringOperations& rhs) const
// {
//     StringOperations loc_obj;
//     size_t len = strlen(this->strmem) + strlen(rhs.strmem);
//     char* buff = new char[len+1];
//     strcpy(buff, loc_obj.strmem);
//     strcat(buff, rhs.get_membstring());
//     StringOperations temp {buff};
//     delete [] buff;
//     return loc_obj;
// }

StringOperations& StringOperations::operator+=(const StringOperations& rhs)
{
    *this =  *this + rhs;
    return *this;
}
//  Buggy code
// StringOperations& StringOperations::operator+=(const StringOperations& rhs)
// {
//     char* l_str{this->strmem};
//     strcat(l_str, rhs.get_membstring());
//     strcpy(strmem, l_str);
//     return *this;
// }


int StringOperations::operator>(const StringOperations& rhs) const
{
    int retval,l;
    
    for (std::size_t i : std::views::iota(size_t{0},strlen(this->strmem)))
        if(this->strmem[i] > rhs.strmem[i])
        {
            retval = 1;
            break;
        }
        else if(this->strmem[i] == rhs.strmem[i])
        {
            retval = 0;
        }
        else
        {
            retval = -1;
            break;
        }
    return retval;
}
int StringOperations::operator<(const StringOperations& rhs) const
{
    int retval;
    retval = (-1 * this->operator>(rhs));
    return retval;
}
bool StringOperations::operator!=(const StringOperations& rhs) const
{
    bool retval = true;
    if (this->operator>(rhs) == 0)
        retval = false;
    return retval;
}
bool StringOperations::operator==(const StringOperations& rhs) const
{
    bool retval = false;
    if (this->operator>(rhs) == 0)
        retval = true;
    return retval;
}
StringOperations& StringOperations::operator*=(const int num)
{
    *this = *this * (num);
    return *this;
}

StringOperations StringOperations::operator*(const int numrep) const
{
    size_t len = strlen(this->strmem);
    len = (len * numrep) + 1;
    auto buff = new char[len];
    buff[0] = '\0';     // strcat, it checks the `\0` for concatinating
                        // if it is not initialized then strcat confuses to concatinate
                        // keeps reading garbage until it finds some accidental '\0', and writes after that.
    for(int i: std::views::iota(0,numrep))
        strcat(buff , this->strmem);
    StringOperations retstr{buff};
    return retstr;
}
