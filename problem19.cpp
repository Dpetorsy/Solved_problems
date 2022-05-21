#include <iostream>

typedef unsigned long long U_LONG;

constexpr U_LONG factorial(unsigned num)
{
    // base case
    if (num <= 1)
        return 1;
    
    U_LONG value = 1;
    for (size_t i = 2; i <= num; ++i)
        value *= i;
    
    return value;
}

int main()
{
    std::cout << factorial(10);

    return 0;
}
