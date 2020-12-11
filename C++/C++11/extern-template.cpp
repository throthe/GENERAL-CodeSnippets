#include <iostream>

// C++11 - Extern template
// http://en.cppreference.com/w/cpp/language/class_template

// DESC: 
// An explicit instantiation declaration (an extern template) prevents implicit instantiations: 
// the code that would otherwise cause an implicit instantiation has to use 
// the explicit instantiation definition provided somewhere else in the program 
// (typically, in another file: this can be used to reduce compilation times)  

// ADV: reduce compile time

// In C++03, the compiler must instantiate a template whenever a fully specified template is encountered in a translation unit. 
// If the template is instantiated with the same types in many translation units, 
// this can dramatically increase compile times. 
// There is no way to prevent this in C++03.

// So C++11 introduced extern template declarations, analogous to extern data declarations.
//C++03 has this syntax to oblige the compiler to instantiate a template:
template class std::vector<MyClass>;
//C++11 now provides this syntax:
extern template class std::vector<MyClass>;
//which tells the compiler not to instantiate the template in this translation unit.

int main()
{

    return 0;
}