cmake_minimum_required(VERSION 3.15)
project(cpp_project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_project main/main.cpp
        ObjectsAndClasses/Movie.cpp
        ObjectsAndClasses/Movie.hpp
        ObjectsAndClasses/Movies.cpp
        ObjectsAndClasses/Movies.hpp
        operator-overloading/operator-overload.cpp
        operator-overloading/operator-overload.hpp
        main/additional.cpp
        main/additional.hpp
        inheritance/inheritance.cpp
        inheritance/inheritance.hpp
        inheritance/Account.cpp
        inheritance/Account.h
        inheritance/Account_Util.cpp
        inheritance/Account_Util.h
        inheritance/Savings_Account.cpp
        inheritance/Savings_Account.h
        inheritance/Checking_Account.cpp
        inheritance/Checking_Account.hpp
        inheritance/Trust_Account.cpp
        inheritance/Trust_Account.hpp
        strings/strings_assignment.hpp
        strings/strings_assignment.cpp
        strings/temporary.cpp)
