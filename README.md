# cpp-expert-topics
Logging my past and current learnings placing here

**C++ is all about Efficiency**

 **The #define inclusions tips to avoid multiple inclusions by compiler as below** 

```c++
    #ifndef _AAAAA_H_
    #define _AAAAA_H_


    #endif
```
**(or)**
```c++
    #pragme once  [Needs to check the compiler support]
```
# Functions
```c++
// Declartion of function in header file
// Put default arguments only in the class declaration (header file).
// Because callers see the header; the .cpp file is hidden.
Checking_Account(const char* name = def_name, double balance = def_balance)

// defintion of function
Checking_Account(const char* name, double balance) 
{
    // Some statements
}
```
in this case you can call function with different ways as below

```c++
// calling the function
Checking_Account();                // uses both defaults
Checking_Account("Kirk");          // name="Kirk", balance=def_balance
Checking_Account("Kirk", 500.0);   // both provided
```


# OOPS C++
## Constructors & Destructors
- Default Constructors and Destructors are created by C++ if there is no 
implementation by user
- If a constructor with arguments is created then you cannot declare an object without initial value,<br> 
you get the compiler error. i.e. we need to declare and define the constructors as per the arguments usage in the code.

```c++
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

// Better way of args constructor with initialization list instead of copying inside
Player::Player(string str, int hlt) : name{str}, health{hlt}{

}
```
> Note<br>
✅ Use emplace_back when you want to avoid an extra copy/move and construct the object directly.<br>
`emplace_back` → constructs the element in place inside the container using the arguments provided.<br>
✅ Use push_back when you already have a fully constructed object.<br>
`push_back` → copies or moves an existing object into the container.
> 

- The assignment way of constructor will consume more run time, by using the initialisation list there will not be any<br> 
additional assignment statements execution before starting of the actual code execution.
- Delegating constructor is a constructor calls the original constructor defined by class.
```c++
class Example {
   public:
   
      // Primary constructor	  
      Example(int value) : data(value) {}

      // Delegating constructor
      Example() : Example(0) {}

   private:
      int data;
};
```
- While developing, Object needs several ways of declaratoin, then corresponding overloading constructor declaration and definition is needed, <br>
otherwise c++ will create default constructor if nothing is defined or gives compiler error, 
- To avoid assumptions it is adviced to define user defined constructors based on need.

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
                                  //      both points to the same address) --> then both obj1 and obj2 members will set to 1000
        
        return 0;
    }                               //<-- First object Destructor calls the destruction, which deletes the already deleted memory<br>
                                    //        --> If it goes further, then Destruction of second object <br>
                                    //                it will further delete again the same invalid memory location<br>
```                                                    
#### Deep copy (Object creation with _L-Value_ reference or [_Copy from another object_])

In deep copy to compensate the memory issue, every time we **create a new heap storage while copying to new object or while constructing new object.**<br>
Therefore, while destructing we don't need to bother about the pointing source(for double delete) as we create a dedicated pointer before copying.<br>
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
Copy Assignment constructor syntax for _L-Value_ reference
```c++
Mystring &Mystring::operator=(const Mystring &rhs){
// <Code for the "=" overloading action>
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}
```

Move assignment constructor for _R-Value_ reference<br>
> after copying, we will derefence the pointer(s) to `nullptr` <br>
```c++
Mystring &operator=(Mystring &&rhs)            // Move assignment
{
     if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}
```


## Inheritance 

**Access Specifiers: public, private and protected access**
•Most common
•Establishes ‘is-a’ relationship between Derived and Base classes

| Access     | Base class  | Derived class  | Outside code  |
|------------|-------------|----------------|---------------|
| private    | ✔️          | ❌              | ❌             |
| protected  | ✔️          | ✔️             | ❌             |
| public     | ✔️          | ✔️             | ✔️            |

**Example syntax**
```c++

class Base
{
    private:
        int a;
    public:
        methods();
};

class Dervied: public Base1, private Base2, protected Base3
{
    // Members of NewClass
};
```

```c++
class Base {
private:
    int a = 1;      // private
protected:
    int b = 2;      // protected
public:
    int c = 3;      // public
};

class Derived : public Base {
public:
    void test() {
        // a = 10;   // ❌ private: NOT accessible in Derived
        b = 20;      // ✅ protected: accessible in Derived
        c = 30;      // ✅ public: accessible
    }
};

int main() {
    Derived d;

    // d.a = 1;     // ❌ private: no
    // d.b = 2;     // ❌ protected: no (from outside)
    d.c = 3;        // ✅ public: works
}
```

**Example syntax** 

```c++
class Base {
// Base class members . . .
};
class Derived: <access-specifier> Base {
// Derived class members . . .
};
```

**Inheritance**

<img src="inheritance/inheritance.png" width="30%" height="30%" alt="">

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
<img src="inheritance/inher_composition.png" width="50%" alt="">



- this is `IS-a` relation between two classes

### Construction and Destruction of inheritance
`Derived der;`
- Base constructor invoked first --> Derived constructor invoked 
- And destructor the oppostie happens Derived destructs first --> Base destructs

- A Derived class does NOT inherit
  - Base class constructors 
  - Base class destructor
  - Base class overloaded assignment operators
  - Base class friend functions
- However, the derived class constructors, destructors, and overloaded <br>
  assignment operators can invoke the base-class versions
- C++11 allows explicit inheritance of base ‘non-special’ constructors with
  - `_using Base::Base;_` anywhere in the derived class declaration
    - If the Derived class is not having constructor with arguments
    - Then it calls corresponding base class constructor with arguments which matches
    - This will cause confusion if `_using Base::Base;_` is used
  - Lots of rules involved, often better to define constructors yourself
  
```c++
class Base {
private:
    int value;
public:
   Base() : value{0} { cout << "Base no-args constructor" << endl; }
   Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
   ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base {
    using Base::Base;
private:
    int doubled_value;
public:
    Derived() : doubled_value {0} { cout << "Derived no-args constructor " << endl; } 
    Derived(int x) : doubled_value {x*2}  { cout << "Derived (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor " << endl; } 
};

int main() {
//   Base b;
//    Base b{100};
 //   Derived d;
 Derived d {1000};
    
    return 0;
}
```
But In General the derived class construcor to be defined as below with explicit base constructor
```c++
    Derived() : 
        Base {}  {
            cout << "Derived no-args constructor " << endl; 
    }
    Derived(int x) 
        : Base{x} , doubled_value {x * 2} { 
            cout << "int Derived constructor" << endl; 
    }
```

- If a derived class doesn't initialize the base class with the ini, that means a no args constructor will be invoked

- Construction call of base class members to be done explicitly in the derived class definition otherwise
constructor will be called instead while creating the derived object

## Polymorphism

Compile Time and Run-time polymorphism

<img src="polymorphism/typesOfPolymorphism.png" width="50%" alt="">

**c++ will do static binding in inheritance but dynamic binding is in Polymorphism**


**The problem**

```c++
class Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};
class Derived: public Base {
public:
    void say_hello()  const {   
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};
void greetings(const Base &obj) {
    std::cout << "Greetings: " ;
    obj.say_hello();
}

int main() {
    Base b;
    b.say_hello();      // Base class
    Derived d;
    d.say_hello();      // Derived class
    
    greetings(b);       // Greetings : Base class
    greetings(d);       // Greetings: Derived class
    
    Base *ptr = new Derived();
    ptr->say_hello();   // Base class pointer
    
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();  // Base class pointer
    delete ptr;
    return 0;
}
```
Polymorphism is in short as below <br>
`<Base Class> *prt = new <Derived Class>`

```c++
    Account *p1 = new Account();     // p1 is variable on stack and it points to an Account type object created on heap
    Account *p2 = new Savings();     // p2 is variable on stack and it points to an Savings type object created on heap
    Account *p3 = new Checking();    // p3 is variable on stack and it points to an Checking type object created on heap
    Account *p4 = new Trust();       // p4 is variable on stack and it points to an Trust type object created on heap
```



if `say_hello()` is declared with `virtual` specifier we can get the dynamic binding(polymorphism)


For polymorphism, we need to have 
- Inheritance
- Base class pointer or Base class reference
- Virtual functions (override the definition dynamically)
  - If any Virtual functions are defined in any class then the class would need a virtual destructor 
  - Otherwise, memory leak or undefined behavior obtains
- Explicit `override` specifier
  - When virtual functions are declared in the Class in multiple classes
  - Then all the function signature and return must be EXACTLY same
  - By mistake if any slight difference, then it is a Redefinition but not `override` 
  - In C++ we have the `override` specifier to throw error at compile time.

>You only need to write either virtual or override, <br>
>BUT the best practice in modern C++ is to use ONLY `override` in derived classes.

| Situation      | Write       | Why                                |
|----------------|-------------|------------------------------------|
| Base class     | `virtual`   | Declares virtual dispatch          |
| Derived class  | `override`  | Ensures correct override; cleaner  |


Problem due to not having `override` specifier

<img src="polymorphism/withoutOVERRIDE.png" width="50%" alt="">

The output will be like

<img src="polymorphism/unintended_output.png" width="50%" alt="">


Compiler error with the `override` specifier

<img src="polymorphism/withOVERRIDE.png" width="50%" alt="">


**`final` Specifier**
<br>When used at class level 
- no further Derivation of Class is possible

When used at the method level
- Prevents virtual method from being overridden in derived classes further (for better compiler optimisation)


**Use Base Class References**
By using the base class references, polymorphism works as below 

```c++
    Account a;
    Account &ref = a;
    ref.withdraw(1000);		    // In Account::withdraw

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000);        // In Trust::withdraw

   Account a1;
   Savings a2;
   Checking a3;
   Trust a4;
   
   do_withdraw(a1, 1000);       // In Account::withdraw
   do_withdraw(a2, 2000);       // In Savings::withdraw
   do_withdraw(a3, 3000);       // In Checking::withdraw
   do_withdraw(a4,  4000);      // In Trust::withdraw
```

**Abstract Base Class**
Abstract Class are the classes
- Cannot instantiate objects
- These classes are used as base classes in inheritance hierarchies 
- Often referred to as Abstract Base Classes

**Concrete class**
- Used to instantiate objects from
- All their member functions are deﬁned
- Checking Account, Savings Account
- Faculty, Staff
- Enemy, Level Boss

> **Friend functions are not inherited** <br>
> Those friend functions to be choosen based on the need in the inherited Class and also should be redefined

Therefore, it is possible to create a class with friend function and that can be used for the base class <br>
that works as an interface class. 

```c++
#include <iostream>

class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable {};
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}


class Account : public I_Printable {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Account display";
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
     virtual void print(std::ostream &os) const override {
        os << "Checking display";
    }
    virtual ~Checking() {  }
};

```

>1. Virtual destructors are crucial for properly destroying derived class objects when they are referred to by base class pointers.
>2. Polymorphism enables objects of derived classes to be treated as objects of a base class, enhancing flexibility in code.
>3. Inheritance enables derived classes to modify or extend the behaviors defined in base classes, which is a core aspect of polymorphism.
>4. Upcasting is a safe and common practice in C++ to use a derived class object where a base class object is expected. 
>(“Using a derived class where a base is expected” = passing a child class to something written for the parent class.)
>5. Virtual functions are used to achieve polymorphism, allowing derived classes to provide specific behavior while using the same interface.
```c++
//1: Function expects a Base, you pass a Derived
class Character {
public:
    virtual void attack() = 0;
};

class Warrior : public Character {
public:
    void attack() override { /* ... */ }
};

void fight(Character* c) {   // expects Base pointer
    c->attack();
}

Warrior w;
fight(&w);   // passing Derived object where Base is expected (upcast)

//2: Storing derived objects in a container of base pointers
std::vector<Character*> chars;

Warrior w;
Sorcerer s;

chars.push_back(&w);  // Derived → Base
chars.push_back(&s);  // Derived → Base
```

**Upcasting (safe)**

Casting Derived → Base.
Happens automatically and is always safe.
```c++
Derived d;
Base* b = &d;        // upcast (implicit)
```
Why safe?
Every Derived is-a Base; no information is lost (except access to derived-specific stuff).

**Downcasting (dangerous)**

Casting Base → Derived.
Needs an explicit cast and is unsafe unless verified.
```c++
Base* b = new Derived;
Derived* d = dynamic_cast<Derived*>(b);  // safe check
```

If b does not actually point to a Derived,
dynamic_cast returns nullptr (for pointers).

⚠️ Why dangerous?

Because the base pointer might actually point to:

- another derived type
- or not be polymorphic 
- or not match the type you expect

Using `static_cast` for downcasting does not check anything → undefined behavior if wrong.

**Polymorphism rule of thumb**<br>
- Use upcasting for polymorphic containers (std::vector<Base*>).
- Use downcasting rarely, only when you truly need derived-specific behavior.


| Cast                           | Safe?        | When to use                                                  |
|--------------------------------|--------------|--------------------------------------------------------------|
| **Upcast (Derived → Base)**    | ✔️ Always    | Allowed, but implicit cast is enough                         |
| **Downcast (Base → Derived)**  | ❌ Dangerous  | Only if *guaranteed* correct; otherwise use `dynamic_cast`   |


```c++
class Animal {
public:
int age;
};

class Dog : public Animal {
public:
int barkPower;
};
```

A Dog has two parts:
[ Animal part ] & [ Dog part ]

An Animal object has only:
[ Animal part ]

**Upcasting**
```c++
Dog d;
Animal* a = &d;   // upcast
```
```shell 
#Dog in memory
+-------------+
| age         |  <-- Animal part
+-------------+
| barkPower   |  <-- Dog part
+-------------+

Animal* a  → looks only at [age]
```

**Downcasting**
```c++
Animal an;
Dog* d = static_cast<Dog*>(&an); // ❌ dangerous

+-------------+
| age         |  <-- Animal part only
+-------------+
this means
+-------------+
| age         |
+-------------+
| barkPower   |  <-- does NOT exist!
+-------------+

d->barkPower = 10;  → You write memory that is not part of the Animal object → corruption → crash.
```


Some Dangerous downcasting Issue
```c++
int main() {
  Animal* animalPtr = new Cat();

  Cat* catPtr = dynamic_cast<Cat*>(animalPtr);  

  if (catPtr != nullptr) {
    catPtr->sound();
    catPtr->scratch();
  } else {
    cout << "Downcasting failed!" << endl;
  }

  delete animalPtr;
  return 0;
}
```

Definition and Declaration of variables<br>
✔️ Allowed in header:
```c++
static const int def_health = 100;
static const int def_power = 10;
```
❌ Not allowed in header:
```c++
static const std::string def_name = "Elden King";
// this requires a definition in cpp file
```

RAII : Resource Allocation Is Initialisation (Smart Pointers)
- Common idiom or pattern used in software design based on container object lifetime
- RAII objects are allocated on the stack
- Resource Acquisition
  - Open a ﬁle
  - Allocate memory
  - Acquire a lock
- Is Initialization
  - The resource is acquired in a constructor
- Resource relinquishing
  - Happens in the destructor
  - Close the ﬁle
  - Deallocate the memory
  - Release the lock


Unique Pointer

Most recomended Pointer type in general coding

**Shared pointer<br>**

`p1.use_count()` will give the number of shared pointers<br>
`p1.reset()` will be used to reset the use counter<br>



```c++
    // Sample code shared between normal and vector of pointers 
    std::cout << "\n==========================================" << std::endl;
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);
    
    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);   // one shared copy for acc1 and vector second copy.
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    
    for (const auto &acc: accounts) {
        std::cout << *acc << std::endl;
        // here the pointer is shared beween acc1 and vector of pinters therefore use count : 2
        std::cout << "Use count: " << acc.use_count() << std::endl;
    }
```

Problem of circular pointer using the Shared pointer
<img src="/smart_pointers/sharedpointer_problem.png" width="60%" alt="">

```c++

int main() {
    shared_ptr<A> a  = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);    // metod to make shared pointer pointed to B
    b->set_A(a);    // metod to make shared pointer pointed to A
    
    return 0;
}

```
<img src="/smart_pointers/output_display.png" width="60%" alt="">

Because of 1 reference available in both A and B destrctor will never call therefore memory leak happens.
<br> To compensate this one of the class will be defined with the weak pointer

```c++
class B {
    std::weak_ptr<A> a_ptr;     // make weak to break the strong circular reference
public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};
```



