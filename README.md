# cpp-learning-journey
Logging my past and current learnings placing here

### The #define inclusions tips to avoid multiple inclusions by compiler as below 


    #ifndef _AAAAA_H_
    #define _AAAAA_H_


    #endif

**(or)**

    #pragme once  [Needs to check the compiler support]

# OOPS C++
## Constructors & Destructors
- Default Constructors and Destructors are created by C++ if there is no 
implementation by user
- If a constructor with arguments is created then you cannot declare an object without initial value,<br> 
you get the compiler error. i.e. we need to declare and define the constructors as per the arguments usage in the code. 
<pre>
Player() <-- class

// no args constructor
Player::Player() {
    name ="None";
    health  = 0;
}
// Better way of no args constructor with initialization list
Player::Player(): name{"None"}, health{0}{

Player::Player(string str, int hlt) {
    name =str;
    health  = hlt;
}

// Better way of no args constructor with initialization list
Player::Player(string str, int hlt) : name{str}, health{hlt}{

}
</pre>
- The assignment way of constructor will consume more run time, by using the initialisation list there will not be any<br> 
additional assignment statements execution before starting of the actual code execution.
- Delegating constructor is a constructor calls the original constructor defined by class.
- If there are several ways of Object declared then corresponding overloading constructor declaration and definition is needed.

>**Efficient way of handling the Constructor is to create a constructor that initializes all the members**<br>
**Therefore, it will accept all the object constructing statements from main code**

### Copy constructor
A **copy constructor** is a special constructor that creates a new object as a **copy of an existing object**.<br>
The copy-constructor is same as normal constructor with same object as input argument<br>
If a copy constructor is not created by class.h then compiler will create its own copy constructor **which is shallow copy constructor**.

#### Shallow copy (Object creation with L-Value reference or [_Copy from another object_])
Shallow copy is copying just each member of source object<br>
If a pointer is present in the members of class then it just copy the address from source<br> 
Therefore it will keep the address, and if the address is freed by destructor or by some means<br>
still the copied member points the address which causes issues later, program might crash also.

```c++
StringOperations(const StringOperations& rhs)
```

```c++
    int main() {
    
        Shallow obj1 {100};        //<-- calls constructor and creates the members for this obj1 and initializes the values
        // Problem1: Destructor will delete the memory address and creates a dangling pointer issue 
        display_shallow(obj1);      //<-- calls copy constructor --> if the copy done shallow by just member copy <br>
                                    //    --> perform the instructions in code --> destruct the copied object and <br>
                                    //    delete the members of copied object (if original pointer contains the address then <br>
                                    //    that address will be deleted now) --> leaves the code and comes back to main 
        // Problem2: modifying one element effects other object value
        Shallow obj2 {obj1};      //<-- calls constructor and creates the members for this obj2 
                                  //          and copies the member values form obj1 which is invalid as it was deleted before
        obj2.set_data_value(1000);//  <-- Set the value to the member as 1000 (in this case pointer is copied from obj1 to obj2 
                                  //      both points to the same address) --> then both obj1 and obj2 members will sets to 1000
        
        return 0;
    }                               //<-- First object Destructor calls the , which deletes the already deleted memory<br>
                                    //        --> If it goes further then Destruction of second object <br>
                                    //                it will further delete again the same invalid memory location<br>
```                                                    
#### Deep copy (Object creation with _L-Value_ reference or [_Copy from another object_])

In deep copy to compensate the memory issue every time we **create a new heap storage while copying to or while constructing new object.**<br>
Therefore, while deleting we don't need to bother about the pointing source as we create a dedicated pointer before copying.<br>
**In short: Allocate a new storage and copy the data**
```c++
StringOperations(const StringOperations& rhs)
```
#### Move Constructor (Object creation with _R-Value_ reference or [_Construct from temporary_])

This is used to `Construct from temporary`
The constructor which is created for object creation for the R-Value initializations.<br>
```c++ 
StringOperations(StringOperations&& rhs)
```

### _this_ Pointer

Two highlighted cases for _this_ pointer is as below 
- When the member of the Class and Constructor argument are same name assignment be like
  - `this.age = age;`
- While comparing the objects in the constructor with passed object address
  - `if (this == &object)`
 
### `const` Qualifier 
- `const` qualifier will not allow to use the members functions after declaration.
- If any method is called using the `const` object it gives the compiler error
- In the class definition if any member is explicitly mentioned as `const` then it can be used
  - `int get_name() const { `, in this case this method is allowed to use for `const` objects also

### `static` Storage class
- Use case is like : how many number of objects created and active now
  - By incrementing the number while constructor is called 
  - By decrementing the number while destructor is called
- To create the specific members and methods only accessible to that particular object
- These static members and methods can be accessible through class name.
  - `Player::get_num_players();`


### Different types of variables and their storages

| Type                 | Memory Segment | Stored In            | Lifetime             |
|----------------------|----------------|----------------------|----------------------|
| **Stack variable**   | Stack          | RAM                  | Until function ends  |
| **Heap variable**    | Heap           | RAM                  | Until freed manually |
| **Global variable**  | Data segment   | RAM                  | Whole program        |
| **Static variable**  | Data segment   | RAM                  | Whole program        |
| **Constants / Code** | Text segment   | RAM (read-only part) | Whole program        |


| Feature    | Stack             | Heap          | Global        | Static        |
|------------|-------------------|---------------|---------------|---------------|
| Allocation | Auto              | Manual        | Auto          | Auto          |
| Lifetime   | Function duration | Until freed   | Whole program | Whole program |
| Scope      | Local             | Pointer-based | Global        | Local or file |
| Speed      | Fast              | Slow          | Fast          | Fast          |
| Control    | Compiler          | Programmer    | Compiler      | Compiler      |


| Type                | Created When                                                | Destroyed When                       | Stored In                             | Scope                       | Lifetime      | Managed By |
|---------------------|-------------------------------------------------------------|--------------------------------------|---------------------------------------|-----------------------------|---------------|------------|
| **Stack variable**  | When function starts                                        | When function ends                   | Stack                                 | Local                       | Temporary     | Compiler   |
| **Heap variable**   | When you call `malloc` / `new`                              | When you call <br> `free` / `delete` | Heap                                  | Any (via pointer)           | Until freed   | Programmer |
| **Global variable** | When program starts                                         | When program ends                    | Data segment <br>(global/static area) | Entire program              | Whole program | Compiler   |
| **Static variable** | When program starts <br>(even if defined inside a function) | When program ends                    | Data segment <br>(global/static area) | Limited to function or file | Whole program | Compiler   |


>✅ Stack, Heap, Global, Static → all live in RAM during execution.<br>
> 🧹 When program ends → OS frees that memory automatically.

>A new vector method for 


## Operator Overloading
Copy constructor syntax for _L-Value_ reference<br>
`Mystring &Mystring::operator=(const Mystring &rhs){`<br>
`<Code for the "=" overloading action>`<br>
`}`

Move constructor for _R-Value_ reference<br>
> after copying we will derefence the pointer(s) to `nullptr` <br>


## Inheritance 

```c++
class Base {
// Base class members . . .
};
class Derived: <access-specifier> Base {
// Derived class members . . .
};
```
access-specifier: public, protected, private

public
•Most common
•Establishes ‘is-a’ relationship between Derived and Base classes

**Inheritance**
```c++
class Base {
public:
    void foo() { }
};

class Derived : private Base {   // private inheritance
public:
    void callFoo() {
        foo();  // allowed internally
    }
};

int main() {
    Derived d;
    // d.foo();   // ❌ error: foo() is private in Derived
    d.callFoo(); // ✅ works
}
```

**Composition**
```c++
class Base {
public:
    void foo() { }
};

class Wrapper {
private:
    Base b;    // composition: has-a

public:
    void callFoo() {
        b.foo();   // call through contained object
    }
};

int main() {
    Wrapper w;
    // w.foo();   // ❌ error: no inheritance
    w.callFoo(); // ✅ works
}
```



- the IS-a relation between two classes 
- If a derived class doesn't initialize the base class with the ini, 

- Construction of base class members to be done explicitly in the derived class definition otherwise
constructor will be called instead while creating the derived object
