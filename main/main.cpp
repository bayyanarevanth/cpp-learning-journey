
#include<iostream>
#include "additional.hpp"

using namespace std;

int main()
{

    // Movies my_movies;
    // cout<<"Hello World!"<<endl;
    // my_movies.display_all_movies();

    // add_movie(my_movies, "Big", "PG-13",2);                 // OK
    // add_movie(my_movies,"Star Wars", "PG",5);             // OK
    // add_movie(my_movies,"Cinderella", "PG",7);           // OK

    // my_movies.display_all_movies();   // Big, Star Wars, Cinderella

    // add_movie(my_movies,"Cinderella", "PG",7);            // Already exists
    // add_movie(my_movies,"Ice Age", "PG",12);              // OK

    // my_movies.display_all_movies();    // Big, Star Wars, Cinderella, Ice Age
    // cout<< my_movies.increment_watched("Cinderella"); 

    // increment_watched(my_movies,"Big");                    // OK
    // increment_watched(my_movies,"Ice Age");              // OK

    // my_movies.display_all_movies();    // Big and Ice Age watched count incremented by 1

    // increment_watched(my_movies,"XXX");         // XXX not found

    cout << boolalpha << endl;
    StringOperations a {"Franka"};
    StringOperations b {"Frank"};
    cout << (a==b) << endl;         // true
    cout << (a!=b) << endl;           // false
    
    b = "george";
    cout << (a==b) << endl;         // false
    cout << (a!=b) << endl;          // true
     cout << (a<b) << endl;         // true
    cout << (a>b) << endl;          // false
    
    StringOperations s1 {"FranK"};
    s1 = ++s1;
    cout << s1 << endl;             // FRANK
    s1 = -s1;
    cout << s1 << endl;             // frank              

     s1 = s1 + StringOperations{"*****"};
    cout << s1 << endl;             // frank*****       

    s1 += "-----";                      // frank*****-----
    cout << s1 << endl;
    
    StringOperations s2{"12345"};
    s1 = (s2 * 3);
    cout << s1 << endl;           // 123451234512345
    
    StringOperations s3{"abcdef"};  
    s3 *= 5;
    cout << s3 << endl;             // abcdefabcdefabcdefabcdefabcdef
    
    StringOperations repeat_string;
    int repeat_times;
    cout << "Enter a string to repeat: " << endl;
    cin >> repeat_string;
    cout << "How many times would you like it repeated? " << endl;
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "The resulting string is: " << repeat_string << endl;
    
    cout << (repeat_string * 12) << endl;
    
    repeat_string = "RepeatMe";
    cout << (repeat_string + repeat_string + repeat_string) << endl;
    
    repeat_string += (repeat_string * 3);
    cout << repeat_string << endl;
    
    repeat_string = "RepeatMe";
    repeat_string += (repeat_string + repeat_string + repeat_string);


    StringOperations s = "frank";
    ++s;
    cout << s << endl;                  // FRANK
    
    s = -s; 
    cout << s << endl;                  // frank
    StringOperations result;
    result = ++s;
    cout << s << endl;                  // FRANK
    cout << result << endl;           // FRANK
    
    s = "Frank";
    ++s;
    cout << s << endl;                  // FRANK
    
    s = -s;
    cout << s << endl;                  // frank
    result = ++s;
    cout << s << endl;                  // FRANK
    cout << result << endl;           // frank */
    return 0;
}

