#include <iostream>
#include <bitset>
#include <cassert>
using std::cin;
using std::cout;
using std::endl;

std::bitset<32> swapGroupOfBits(int n, int p, int r, int q);
void swapBits(std::bitset<32>& numBitset, int p, int r);

int main()
{
    unsigned n = 0;
    unsigned p = 0;
    unsigned r = 0;
    unsigned q = 0;
    
    cout << "Input number: ";
    cin >> n;
    cout << "Input p: ";
    cin >> p;
    cout << "Input r: ";
    cin >> r;
    cout << "Input q: ";
    cin >> q;
    
    std::bitset<32> swapedNum = swapGroupOfBits(n, p, r, q);
    cout << endl << "Swaped " << n << " = " << swapedNum.to_ulong() << " : " << swapedNum;
    cout << endl;
    return 0;
}

std::bitset<32> swapGroupOfBits(int n, int p, int r, int q)
{
    assert(p < 32 && r < 32);
    
    unsigned len = 32 - r;
    std::bitset<32> numBitset = n;
    
    for (size_t i = 0; (i < q && i < len); ++i)
    {
        swapBits(numBitset, p, r);
        ++p;
        ++r;
    }
    
    return numBitset;
}

void swapBits(std::bitset<32>& numBitset, int p, int r)
{
    std::bitset<1> tmpBit;
    
    tmpBit[0] = numBitset[r];
    numBitset[r] = numBitset[p];
    numBitset[p] = tmpBit[0];
}
