#include <iostream>

template <unsigned num>
struct Factorial {
  enum { value = num * Factorial<num - 1>::value };
};

// base case
template <>
struct Factorial<0> {
  enum { value = 1 };
};

int main()
{
    std::cout << Factorial<10>::value;

    return 0;
}
