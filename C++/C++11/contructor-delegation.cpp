#include <iostream>

// In C++03, constructors of a class are not allowed to call other constructors in an initializer list of that class. 
// Each constructor must construct all of its class members itself or call a common member function, as follows:

class Foo  {
    int number;
private:
    void Construct(int new_number)  { number = new_number; }
public:
     Foo (int new_number)   { Construct(new_number); }
     Foo ()  { Construct(42); }
};

// Constructors for base classes cannot be directly exposed to derived classes; 
// each derived class must implement constructors even if a base class constructor would be appropriate. 
// Non-constant data members of classes cannot be initialized at the site of the declaration of those members. 
// They can be initialized only in a constructor.

// C++11 provides solutions to all of these problems.

// C++11 allows constructors to call other peer constructors (termed delegation). 
// This allows constructors to utilize another constructor's behavior with a minimum of added code. 

// This syntax is as follows:

class Bar  {
    int number;
public:
    Bar (int new_number) : number(new_number) {}
    Bar () : Bar (42) {}
};

// Notice that, in this case, the same effect could have been achieved by making new_number a defaulting parameter. 
// The new syntax, however, allows the default value (42) to be expressed in the 
// implementation rather than the interface — a benefit to maintainers of library code 
// since default values for function parameters are “baked in” to call sites, 
// whereas constructor delegation allows the value to be changed without recompilation of the code using the library.

// This comes with a caveat: C++03 considers an object to be constructed when its constructor finishes executing,
// but C++11 considers an object constructed once any constructor finishes execution.
// Since multiple constructors will be allowed to execute, 
// this will mean that each delegating constructor will be executing on a fully constructed object of its own type. 
// Derived class constructors will execute after all delegation in their base classes is complete.

// For base-class constructors, C++11 allows a class to specify that base class constructors will be inherited. 
// Thus, the C++11 compiler will generate code to perform the inheritance and the forwarding of the derived class to the base class.
// This is an all-or-nothing feature: either all of that base class's constructors are forwarded or none of them are. 
// Also, restrictions exist for multiple inheritance, 
// such that class constructors cannot be inherited from two classes that use constructors with the same signature.
// Nor can a constructor in the derived class exist that matches a signature in the inherited base class.

// The syntax is as follows:
class BaseClass {
public:
    BaseClass(int value);
};

class DerivedClass : public BaseClass {
public:
    using BaseClass::BaseClass;
};

// For member initialization, C++11 allows this syntax:
class SomeClass {
public:
    SomeClass() {}
    explicit SomeClass(int new_value) : value(new_value) {}

private:
    int value = 5;
};

// Any constructor of the class will initialize value with 5, 
// if the constructor does not override the initialization with its own. 
// So the above empty constructor will initialize value as the class definition states, 
// but the constructor that takes an int will initialize it to the given parameter.

// It can also use constructor or uniform initialization, 
// instead of the assignment initialization shown above.

int main()
{
    return 0;
}