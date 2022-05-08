#include <iostream>
#include <string>
#include <stdarg.h>
using std::cout;
using std::endl;
using std::string;

string  replace(string str, ...);

int main()
{
    string str = "aa# nn # cc## e";
    
    cout << "Your string: " << str << endl;
    cout << "Replaced string: " << replace(str, 3, 12, -2, 1) << endl;
}

string replace(string str, ...)
{
    va_list ap;
    va_start(ap, str);
    
    size_t sharpIndex = 0;
    while ((sharpIndex = str.find("#")) != string::npos)
        str.replace(sharpIndex, 1, std::to_string(va_arg(ap, int)));
    
    va_end(ap);
    return str;
}
