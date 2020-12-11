#include <iostream>

// C++ - Constant Expressions (constexpr specifier)
// http://en.cppreference.com/w/cpp/language/constexpr
// Desc: constexpr - specifies that the value of a variable or function can appear in constant expressions 


// C++ has always had the concept of constant expressions. 
// These are expressions such as 3+4 that will always yield the same results, at compile time and at run time. 
// Constant expressions are optimization opportunities for compilers, 
// and compilers frequently execute them at compile time and hardcode the results in the program. 
// Also, in several places, the C++ specification requires using constant expressions. 
// Defining an array requires a constant expression, and enumerator values must be constant expressions.

// However, a constant expression has never been allowed to contain a function call or object constructor. 
// So a piece of code as simple as this is illegal:

// int get_five1() {return 5;}
///int some_value[get_five1() + 7];             // ERROR: Create an array of 12 integers. Ill-formed C++

// This was not legal in C++03, because get_five() + 7 is not a constant expression. 
// A C++03 compiler has no way of knowing if get_five() actually is constant at runtime. 
// In theory, this function could affect a global variable, call other non-runtime constant functions, etc.

// C++11 introduced the keyword constexpr, 
// which allows the user to guarantee that a function 
// or object constructor is a compile-time constant.
// The above example can be rewritten as follows:
constexpr int get_five() {return 5;}
int some_value[get_five() + 7];             // OK: Create an array of 12 integers. Legal C++11

// This allows the compiler to understand, and verify, that get_five() is a compile-time constant.

// Using constexpr on a function imposes some limits on what that function can do. 
// First:   - the function must have a non-void return type. 
// Second:  - the function body cannot declare variables or define new types. 
// Third:   - the body may contain only declarations, null statements and a single return statement. 
// There must exist argument values such that, after argument substitution, 
// the expression in the return statement produces a constant expression.

// Before C++11, the values of variables could be used 
// in constant expressions only if the variables are declared const, 
// have an initializer which is a constant expression, 
// and are of integral or enumeration type. 

// C++11 removes the restriction that the variables must be of 
// integral or enumeration type if they are defined with the constexpr keyword:
constexpr double earth_gravitational_acceleration = 9.8;
constexpr double moon_gravitational_acceleration = earth_gravitational_acceleration / 6.0;

// Such data variables are implicitly const, 
// and must have an initializer which must be a constant expression.

// To construct constant expression data values from user-defined types, 
// constructors can also be declared with constexpr. 
// A constexpr constructor's function body can contain only declarations and null statements, 
// and cannot declare variables or define types, as with a constexpr function.
// There must exist argument values such that, 
// after argument substitution, it initializes the class's members with constant expressions.
// The destructors for such types must be trivial.

// The copy constructor for a type with any constexpr constructors 
// should usually also be defined as a constexpr constructor, 
// to allow objects of the type to be returned by value from a constexpr function. 
// Any member function of a class, such as copy constructors, operator overloads, etc., 
// can be declared as constexpr, so long as they meet the requirements for constexpr functions. 
// This allows the compiler to copy objects at compile time, perform operations on them, etc.

// If a constexpr function or constructor is called with arguments which aren't constant expressions, 
// the call behaves as if the function were not constexpr, 
// and the resulting value is not a constant expression. Likewise, 
// if the expression in the return statement of a constexpr function does not 
// evaluate to a constant expression for a given invocation, the result is not a constant expression.


// EXAMPLE1: Constexpr functions
constexpr int factorial(int n) {
    return n <= 1? 1 : (n * factorial(n - 1));      // C++11 constexpr functions use recursion rather than iteration
}

// EXAMPLE2: Constexpr functions


//EXAMPLE3: output function that requires a compile-time constant, for testing
template<int n> struct ConstN {
    ConstN() { std::cout << n << '\n'; }
};

int main()
{
    std::cout << "4! = " ;
    ConstN<factorial(4)> out1;                          // computed at compile time

    volatile int k = 8;                                 // disallow optimization using volatile
    std::cout << k << "! = " << factorial(k) << '\n';   // computed at run time

    return 0;
}