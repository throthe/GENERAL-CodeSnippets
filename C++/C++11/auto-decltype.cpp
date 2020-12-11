// http://www.cprogramming.com/c++11/c++11-auto-decltype-return-value-after-function.html


Auto, References, Pointers and Const
One question that is sure to come up is how auto handles references: int& foo();

auto bar = foo(); // int& or int?

The short answer is in C++11, auto defaults to being by-value for references, so in the above code bar is an int. However, you can add the & as a modifier to force it to be a reference: int& foo();

auto bar = foo(); // int
auto& baz = foo(); // int&

On the other hand, if you have a pointer auto will automatically pick up pointerness: int* foo();

auto p_bar = foo(); // int*

But you can also (thankfully) be explicit about it, and indicate that the variable is a pointer: int* foo();
auto *p_baz = foo(); // int*

You can similarly tack const onto auto if you need it, when dealing with references: int& foo();

const auto& baz = foo(); // const int&

Or with pointers: int* foo();
const int* const_foo();
const auto* p_bar = foo(); // const int*
auto p_bar = const_foo(); // const int*


Overall, it feels quite natural and normal, and it follows the normal type inference rules of templates in C++.
