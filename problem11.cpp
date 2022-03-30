#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned leftShift(const unsigned n, const unsigned d);

int main()
{
    unsigned n = 0;
    unsigned d = 0;
    
    cout << "Input n: ";
    cin >> n;
    cout << "Input d: ";
    cin >> d;
    
    cout << endl << n << " << " << d << " = " << leftShift(n, d) << endl;
    return 0;
}

unsigned leftShift(const unsigned n, const unsigned d)
{
    return (n << d | (n >> (32 - d)));
}
