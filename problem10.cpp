#include <iostream>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;

unsigned findMod(const unsigned n, const unsigned d);
bool isPowerOfTwo(const unsigned d);

int main()
{
    unsigned n = 0;
    unsigned d = 0;
    
    cout << "Input n: ";
    cin >> n;
    cout << "Input d(power of 2): ";
    cin >> d;
    
    cout << endl << n << " mod " << d << " = " << findMod(n, d) << endl;
    return 0;
}

unsigned findMod(const unsigned n, const unsigned d)
{
    assert(isPowerOfTwo(d));
    return (n & (d - 1));
}

bool isPowerOfTwo(const unsigned d)
{
    return (d && !(d & (d - 1)));
}
