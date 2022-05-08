#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T, typename... Types>
string  replace(string str, T arg1, Types... arg2);

int main()
{
    string str = "aa# nn # cc## e";
    
    cout << "Your string: " << str << endl;
    cout << "Replaced string: " << replace(str, 3, 12, -2, 1) << endl;
}

string replace(string str)
{
    return str;
}

template <typename T, typename... Types>
string replace(string str, T arg1, Types... arg2)
{
	auto it = str.find("#");
	if (it != std::string::npos)
    	str.replace(it, 1, std::to_string(arg1));
    
    return (replace(str, arg2...));
}
