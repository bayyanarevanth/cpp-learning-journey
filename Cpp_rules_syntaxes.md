# cpp-learning-journey

### ⚙️ Modern C++ — Top 10 Core Rules and principles

1. **Rule of Zero / Three / Five**
  - **Zero** → Let compiler manage everything if your class doesn’t own resources.
  - **Three** → If you define a destructor, copy constructor, or copy assignment — define all three.
  - **Five** → In C++11+, also include move constructor and move assignment.
  - ✅ Prefer **Rule of Zero** when using RAII and smart pointers.

These govern object lifetime and resource management.

| Rule                 | Meaning                                                                                                                                                              | When to Use                                               |
| -------------------- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------|
| 🟢 **Rule of Zero**  | If your class doesn’t manage resources<br> (no `new`, `delete`, file handles, etc.), <br>**don’t define** special member functions — <br>let the compiler handle it. | Most modern C++ <br>(use smart pointers, STL containers). |
| 🟡 **Rule of Three** | If you define one of: destructor, <br>copy constructor, copy assignment → <br>you probably need all three.                                                           | C++98 style classes.                                      |
| 🔵 **Rule of Five**  | Same as above, but include **move constructor** <br> and **move assignment operator**.                                                                               | C++11 and newer.                                          |

🧠 Modern tip: Prefer **Rule of Zero whenever possible — rely on RAII** and smart pointers.

2. **RAII (Resource Acquisition Is Initialization)**
  - Manage resources (memory, files, sockets) through objects.
  - Constructor acquires, destructor releases automatically.
  - Example: `std::unique_ptr`, `std::lock_guard`, `std::fstream`.

Manage resources with objects whose destructors release them automatically.

✅ Example:
```c++
std::unique_ptr<int> ptr = std::make_unique<int>(10);
// Automatically deleted when 'ptr' goes out of scope 
```



3. **Use Smart Pointers Instead of Raw `new` / `delete`**
  - `std::unique_ptr` → sole ownership.
  - `std::shared_ptr` → shared ownership.
  - `std::weak_ptr` → observer.
  - ⚠️ Writing `new` or `delete` directly is a red flag.

4. **Use `= default` and `= delete`**
  - Explicitly tell the compiler which operations are allowed or forbidden.
  - Example:
    ```c++
    Foo() = default;            // allow default construction
    Foo(const Foo&) = delete;   // disallow copy
    Foo(Foo&&) = default;       // allow move
    ```

5. **Use `auto` and Type Deduction Wisely**
  - Reduces redundancy and improves maintainability.
  - Example: `auto it = vec.begin();   // instead of std::vector<int>::iterator`
  - ⚠️ Avoid `auto` when it hides meaningful types (in public APIs).

6. **Prefer Range-Based Loops and STL Algorithms**
  - Example:
    ```c++
    for (const auto& item : container)
        item.display();
    ```  
  - Or use STL algorithms:
    ```c++
    std::for_each(begin(v), end(v), [](auto& x){ x.show(); });
    ```

7. **Const-Correctness Everywhere**
  - Mark methods `const` if they don’t modify object state.
  - Enables compiler checks and safer code.
  - Example: `int get_count() const;` <br>
    `int get_watched_cnt() const { return watched; }`<br>
     `void display() const;`
    <br>This allows usage with `const` objects and avoids accidental modification.
8. **Prefer STL Containers (`std::vector`, `std::string`, etc.)**
  - Avoid raw arrays or manual memory management.
  - Provides safety, exception handling, and simplicity.

9. **Use `constexpr`, `noexcept`, and `override`**
  - `constexpr` → for compile-time constants or functions.
  - `noexcept` → guarantees no exceptions thrown.
  - `override` → ensures proper overriding in inheritance hierarchies.
    ```c++
    class Base {
    virtual void speak() const noexcept = 0;
    };
    
    class Derived : public Base {
    void speak() const noexcept override { std::cout << "Hi"; }
    };
    ```

10. **Prefer Composition Over Inheritance**
  - Favor “has-a” relationships over “is-a” unless inheritance or polymorphism is needed.
  - Example:
    ```c++
    class Car {
        Engine engine;  // has-a relationship
    };
    ```
---

### 🧭 Summary
Modern C++ is about **clarity**, **safety**, and **intent**:
> Let the compiler and STL do the heavy lifting — write expressive, predictable, and resource-safe code.


### Range based for loop from C++20 onwards and c++17
```c++  
  // C++20
  for(int i: std::views::iota(0,numrep))
    std::cout<< i<< endl;

  // until C++17
  for (int i = 0; i < n; ++i)
    std::cout<< i<< endl;
```



| Declaration            | Pointer const? | Value const? | Must initialize at declaration?                              |
|------------------------|----------------|--------------|--------------------------------------------------------------|
| `int *const p`         | Yes            | No           | **YES**                                                      |
| `const int *p`         | No             | Yes          | **NO**                                                       |
| `int const *p`         | No             | Yes          | **NO**                                                       |
| `const int * const p`  | Yes            | Yes          | **YES**                                                      |
| `int const * const x;`  | Yes            | Yes          | **YES**                                                      |
| `const int const *p;`  | No             | Yes          | **This is invalid statement<br> most compilers gives error** |

Sequence of operations: Division, Multiplication, Addition, Subtraction

```c++
int (*a)[10]; // is an array of 10 then a is a pointer points to 10 integers

int *a[10];   // this is a pointer arry those are pointing to integers
```
| Declaration    | Meaning                                       |
| -------------- | --------------------------------------------- |
| `int (*a)[10]` | **a is a pointer** to an **array of 10 ints** |
| `int *a[10]`   | **a is an array** of **10 pointers to int**   |

**Union**
A union shares memory between all members.<br>
The size of a union is given by the largest member.
```c++ /c
union {
int *ptr;
unsigned long e;
} D;

D.e = 0x1122334455667788;

printf("%p\n", obj.D.ptr); // this prints the pointer whose pattern 

// Reverese direction

int a = 10;
obj.D.ptr = &a;  // store pointer
printf("%lx\n", obj.D.e); // this print the pointer as an unsigned long


```

**Structure Padding**
Architecture of a computer processor is such a way that it can **read 1 word
(4 byte in 32 bit processor) from memory at a time**.<br> To make use of this advantage of
processor, data are always aligned as 4 bytes package which leads to insert empty<br>
addresses between other member’s address.<br>


**Promotion Cheat Sheet**

| Operand A     | Operand B     | Result Type                       | Notes                    |
| ------------- | ------------- | --------------------------------- | ------------------------ |
| int           | float         | float                             | int → float              |
| float         | double        | double                            | float → double           |
| double        | long double   | long double                       |                          |
| int           | long long     | long long                         |                          |
| unsigned int  | long long     | long long *or* unsigned long long | depends on widths        |
| int           | unsigned int  | unsigned int                      | unsigned wins            |
| short         | int           | int                               | short → int              |
| char          | int           | int                               | char → int               |
| unsigned char | int           | int                               | if all values fit in int |
| signed int    | unsigned long | unsigned long                     | unsigned wins            |
| long          | double        | double                            | long → double            |



**A sting copy simple definition**<br>
Kernighan & Ritchie used this exact expression to implement:<br>
The idiom is a historical C pattern for copying strings<br>
```c++ /c
while (*c++ = *d++) 
```

**Format Specifiers in C**

```shell
%d %i   → signed int
%u      → unsigned int
%f      → float/double
%c      → char
%s      → string
%p      → pointer
%x %X   → hex
%ld     → long
%lld    → long long
```

| Pointer type                  | Example                        | Memory type          | Writable? | Modify allowed? |
| ----------------------------- | ------------------------------ | -------------------- | --------- | --------------- |
| **Pointer to RAM**            | `char *p = (char*)0x20000000;` | RAM                  | ✔ Yes     | ✔ Safe          |
| **Pointer to array in RAM**   | `char s[] = "abc";`            | RAM                  | ✔ Yes     | ✔ Safe          |
| **Pointer to string literal** | `char *s = "abc";`             | Flash / ROM / rodata | ❌ No      | ❌ UB            |

In embedded systems, you can modify through char/uint8_t only if the pointer points to **RAM**.

```c++
sum(10, 20);   // 10 and 20 are actual parameters

int sum(int a, int b)   // a and b are formal parameters
{
return a + b;
}
```


**Bugs of using macros**<br>

```c++

#define square(x) x*x
#define SQR(x) ((x) * (x))
main()
{
    int i;
    i = 64/square(4);   // output is 64 due to operator precedence after replacing the code
    printf("%d",i);     
    
    
    printf("%d\n",SQR(i++)); // expands to (i++ * i++) : 64*65 or undefined
    printf("%d\n",i); // 66  
}
```

```c++

int a[3]={1,2,3} ;
void main(void)
{
int *pi;
pi=++a;
}
*pi = …

```
Error saying ++a missing l-value array pointer cannot be incremented.


In the strings context 
```c++
int main()
{
    char* s = "CLanguage";                      // allocation of memory section is unknown so const is suggestable
    char* y;
    s[0] = 'c';         // is not allowed - error // ❌ undefined behavior
    char a[] = "Clanguage", b[];                // it creates the variables in RAM
    b = "Clang";        // is not allowed - error
    y = *(s+3);         //y = "nguage";
}
```

| Pointer type                  | Example                        | Memory type          | Writable? | Modify allowed? |
| ----------------------------- | ------------------------------ | -------------------- | --------- | --------------- |
| **Pointer to RAM**            | `char *p = (char*)0x20000000;` | RAM                  | ✔ Yes     | ✔ Safe          |
| **Pointer to array in RAM**   | `char s[] = "abc";`            | RAM                  | ✔ Yes     | ✔ Safe          |
| **Pointer to string literal** | `char *s = "abc";`             | Flash / ROM / rodata | ❌ No      | ❌ UB            |


This is undefined<br>
**C/C++ standard says**: 
If a variable is modified more than once without an intervening sequence point, the behavior is undefined.<br>
It can produce any result not necessarily 19 or 20 as below code

```c++
int main()
{
int a = 2;
int b = 0;
b = ++a+1+(++a+1+a++)+1+(++a);
printf("b=%d, a = %d",b,a);
return 0;
}
```

int function( int arr[], int size );<br>
int function( int *arr, int size );    //both are same declrations


| Syntax        | What compiler sees |
| ------------- | ------------------ |
| `int arr[]`   | `int *arr`         |
| `int arr[10]` | `int *arr`         |
| `int *arr`    | `int *arr`         |
