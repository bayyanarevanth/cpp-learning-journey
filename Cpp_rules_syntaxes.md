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