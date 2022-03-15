#include <iostream>
#include <string>

int main()
{
    std::string str;
    
    std::cout << "Enter your string: ";
    
    std::getline(std::cin , str);
    int size = str.size();
    
    for(int i = 0 ; i < size / 2; ++i)
    {
        std::swap(str[i] , str[size - i - 1]);
    }
    
    std::cout << "Reversed string: " << str << std::endl;
    
    return 0;
}
