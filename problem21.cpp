#include <iostream>

auto mult(int a)
{
    return [a](int b) {
        return a * b;
    };
}

int main()
{
    std::cout << mult(5)(8) << std::endl;

    return 0;
}
