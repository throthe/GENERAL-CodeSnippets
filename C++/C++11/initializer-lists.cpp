#include <iostream>
#include <vector>

// C++11 - List-Initialization
// http://en.cppreference.com/w/cpp/language/list_initialization
// TBD: 

// C++03 inherited the list-initialization feature from C. 
// A struct or array is given a list of arguments in braces, 
// in the order of the members' definitions in the struct. 
// These initializer-lists are recursive, 
// so an array of structs or struct containing other structs can use them.

// -------------- C++03 
struct Object {
    float first;
    int second;
};
Object scalar = {0.43f, 10};                                    //One Object, with first=0.43f and second=10
Object anArray[] = {{13.4f, 3},{43.28f, 29}, {5.934f, 17}};     //An array of three Objects

// This is very useful for static lists, or initializing a struct to some value. 
// C++ also provides constructors to initialize an object, 
// but they are often not as convenient as the initializer list. 
// However, C++03 allows initializer-lists only on structs and classes 
// that conform to the Plain Old Data (POD) definition; 


// C++11 extends initializer-lists, 
// so they can be used for all classes including standard containers like std::vector.

// C++11 binds the concept to a template, called std::initializer_list. 
// This allows constructors and other functions to take initializer-lists as parameters. 
// For example:
class SequenceClass {
public:
    SequenceClass(std::initializer_list<int> list) {
        for (auto& y : list) {
            std::cout << "Value SequenceClass::lists y: " << y << "\n"; 
        }
    };
};

// This constructor is a special kind of constructor, called an initializer-list-constructor. 
// Classes with such a constructor are treated specially during uniform initialization (see below)

// The class std::initializer_list<> is a first-class C++11 standard library type. 
// However, they can be initially constructed statically by the C++11 compiler only via use of the {} syntax.
// The list can be copied once constructed, though this is only a copy-by-reference. 
// An initializer list is constant; its members cannot be changed once the initializer list is created, 
// nor can the data in those members be changed.

// Because initializer_list is a real type, 
// it can be used in other places besides class constructors. 

// EXAMPLE1: Functions with initializer list as argument
void foo(std::initializer_list<float> list) {
    for(auto& x : list) {
        std::cout << "Value x: " << x << "\n"; 
    }
}

// EXAMPLE2: Standard containers with initializer list
std::vector<std::string> v = { "xyzzy", "plugh", "abracadabra" };
std::vector<std::string> v1({ "xyzzy", "plugh", "abracadabra" });
std::vector<std::string> v2{ "xyzzy", "plugh", "abracadabra" };     // see "Uniform initialization"

// EXAMPLE3: // list-initialization in non static member & member in ctor
struct Bar {
    std::vector<int> mem = {1,2,3};         // list-initialization of a non-static member
    std::vector<int> mem2;
    Foo() : mem2{-1, -2, -3} {}             // list-initialization of a member in ctor
};

// EXAMPLE4: list-initialization in return statement
std::pair<std::string, std::string> baz(std::pair<std::string, std::string> pair) {
    return {pair.second, pair.first}; 
}

int main()
{
    // SequenceClass from above can be constructed from a sequence of integers:
    SequenceClass some_var = {1, 4, 5, 6};

    // foo from above can be initialized from a sequence of floats:
    foo({1.0f, -3.45f, -0.4f});

    // Nested list-initialization
    std::string string1{'a', 'b', 'c', 'd'}; // initializer-list constructor call
    std::map<int, std::string> map = { {1, "a"}, {2, {'a', 'b', 'c'} }, {3, string1} };

    return 0;
}