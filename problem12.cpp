#include <iostream>
using std::cout;
using std::endl;

bool isPowerOfTwo(const unsigned n);
bool isPowerOfFour(const unsigned n);

int main()
{
    unsigned n = 0;

    cout << "Input number: ";
    std::cin >> n;
    cout << endl;

    isPowerOfFour(n) ? cout << "True" : cout << "False";
    cout << endl;
    
    return 0;
}

bool isPowerOfTwo(const unsigned n)
{
    return (n && !(n & (n - 1)));
}

bool isPowerOfFour(const unsigned n)
{
    return (isPowerOfTwo(n) && !(n & 0xAAAAAAAA));
}
