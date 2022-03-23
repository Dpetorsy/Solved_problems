#include <iostream>
#include <sstream>
#include <string>
using std::string;

void getUsersString(char* const str, const size_t& size);
void displayRevStr(string* rev_words, int last_index);
void revereseWords(char* const arr);

int main()
{
    constexpr size_t max_str_size = 100;
    char arr[max_str_size + 1];
    
    getUsersString(arr, max_str_size);
    revereseWords(arr);
    
    return 0;
}

// User input string
void getUsersString(char* const str, const size_t& size)
{
    std::cout << "Enter your string :\n";
    std::cin.getline(str, size);
}

// Get words from stringstream and put in str array
void revereseWords(char* const arr)
{
    constexpr size_t max_rev_words_size = 20;
    string str = arr;
    string temp_str;
    std::stringstream s(str);
    string rev_words[max_rev_words_size];
    size_t i = 0;
    
    while (getline(s, temp_str, ' '))
    {
        rev_words[i] = temp_str + " ";
        ++i;
    }
    
    displayRevStr(rev_words, i - 1);
}

// Reverese and display string array
void displayRevStr(string* rev_words, int last_index)
{
    std::cout << "Reversed string :\n";
    while (last_index >= 0)
    {
        std::cout << rev_words[last_index];
        --last_index;
    }
    std::cout << std::endl;
}
