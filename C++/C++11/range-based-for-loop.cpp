#include <iostream>

// C++11 - Range based for-loop
// http://en.cppreference.com/w/cpp/language/range-for
// DESC: Executes a for loop over a range. 
// Used as a more readable equivalent to the traditional for loop operating over a range of values, such as all elements in a container. 

// C++11 extends the syntax of the for statement to allow for easy iteration over a range of elements:
// This form of for, called the “range-based for”, will iterate over each element in the list. 
// It will work for C-style arrays, initializer lists, 
// and any type that has begin() and end() functions defined for it that return iterators. 
// All the standard library containers that have begin/end pairs will work with the range-based for statement.

int main()
{
    std::cout << "C++11 - Range-based for loop\n"; 

    int my_array[5] = {1,2,3,4,5};
    for(int& x : my_array)
    {   
         x *= 2;
         std::cout << "Value x: " << x << "\n"; 
    }

    // similar but also using type inference for array elements
    for(auto& x : my_array)
    {
        x *= 2;
        std::cout << "Value x: " << x << "\n"; 
    }


    std::vector<int> v = {0, 1, 2, 3, 4, 5};
 
    for (const int& i : v)              // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (auto i : v)                    // access by value, the type of i is int
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (auto&& i : v)                  // access by reference, the type of i is int&
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (int n : {0, 1, 2, 3, 4, 5})    // the initializer may be a braced-init-list
        std::cout << n << ' ';
    std::cout << '\n';
 
    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a)                     // the initializer may be an array
        std::cout << n << ' ';
    std::cout << '\n';
 
    for (int n : a)  
        std::cout << 1 << ' ';          // the loop variable need not be used
    std::cout << '\n';

    return 0;
}