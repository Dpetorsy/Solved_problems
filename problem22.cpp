#include <iostream>

auto mult(int a)
{
    return [a](int b) {
        int tmp1 = a * b;
        return [tmp1](int c) {
            int tmp2 = tmp1 * c;
            return [tmp2](int d) {
                int tmp3 = tmp2 * d;
                return [tmp3](int e) {
                    return tmp3 * e;
                };
            };
        };
    };
}

int main()
{
    std::cout << mult(2)(7)(-8)(6)(3) << std::endl;

    return 0;
}
