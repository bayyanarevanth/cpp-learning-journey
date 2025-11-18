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
        main/additional.hpp)
