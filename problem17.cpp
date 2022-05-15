#include <iostream>

int nextPowerOfTwo(int num);

int main()
{
    int num = 0;
    
    std::cout << "Print number: ";
    std::cin >> num;

    std::cout << "Next power of 2 is ";
    std::cout << nextPowerOfTwo(num) << std::endl;
}

int nextPowerOfTwo(int num)
{
    num |= num >> 1;
    num |= num >> 2;
    num |= num >> 4;
    num |= num >> 8;
    num |= num >> 16;
    
    return (num + 1);
}
