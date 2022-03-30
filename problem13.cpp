#include <iostream>
#include <bitset>
#include <cassert>
using std::cin;
using std::cout;
using std::endl;

std::bitset<32> swapBits(const unsigned n, const unsigned p, const unsigned r);

int main()
{
    unsigned n = 0;
    unsigned p = 0;
    unsigned r = 0;
    
    cout << "Input number: ";
    cin >> n;
    cout << "Input p: ";
    cin >> p;
    cout << "Input r: ";
    cin >> r;
    
    std::bitset<32> swapedNum = swapBits(n, p, r);
    cout << endl << "Swaped " << n << " = " << swapedNum.to_ulong() << " : " << swapedNum;
    cout << endl;
    return 0;
}

std::bitset<32> swapBits(const unsigned n, const unsigned p, const unsigned r)
{
    assert(p < 32 && r < 32);
    
    std::bitset<32> numBitset = n;
    std::bitset<1> tmpBit;
    
    tmpBit[0] = numBitset[r];
    numBitset[r] = numBitset[p];
    numBitset[p] = tmpBit[0];
    
    return numBitset;
}
