#include <iostream>
#include <cstring>
#define ARRAY_MAX_SIZE 10
#define STR_MAX_SIZE 50
using std::string;
using std::cout;
using std::endl;

size_t  getArrSize();
void    getUserNums(unsigned nums[], const size_t size);
void    numsToStr(string nums[], unsigned arr[], const size_t size);
void    sortNums(string nums[], const size_t size);
void    catNums(string nums[], const size_t size, string& concat);
void    print(string nums[], const size_t size);

int main()
{
    size_t arrSize = ARRAY_MAX_SIZE;
    arrSize = getArrSize();
    if (arrSize <= 0 || arrSize >= 500)
    {
        cout << "Array size error, try again." << endl;
        exit(1);
    }
    
    unsigned arr[arrSize];
    getUserNums(arr, arrSize);
    
    string numsStr[arrSize];
    numsToStr(numsStr, arr, arrSize);
    
    sortNums(numsStr, arrSize);
    print(numsStr, arrSize);
    
    string concated = "";
    catNums(numsStr, arrSize, concated);
    
    cout << "\nLargest possible number is: " << concated << endl;
    
    return 0;
}

size_t getArrSize()
{
    size_t size;
    cout << "Input array size: ";
    std::cin >> size;
    cout << endl;
    return size;    
}

void getUserNums(unsigned nums[], const size_t size)
{
    cout << "Input array elements: ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cin >> nums[i];
    }
    cout << endl;
}

void numsToStr(string nums[], unsigned arr[], const size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        nums[i] = std::to_string(arr[i]);
    }
}

void sortNums(string nums[], const size_t size)
{
    string tempStr;
    string subStr;
    int cmp;

    for(size_t i = 0; i < size - 1; ++i)
    {
        for(size_t j = 0; j < size - i - 1; ++j)
        {
            if ((cmp = nums[j].string::compare(nums[j + 1])) < 0)
            {
                if (cmp > -49 && (nums[j + 1][nums[j + 1].length() - 1] < nums[j + 1][nums[j + 1].length() - 2]))
                    continue;
                    
                subStr = nums[j + 1].string::substr(0, nums[j].length());
                if (cmp > -49 && (nums[j].string::compare(subStr) == 0) && (nums[j][nums[j].length() - 1] > nums[j + 1][nums[j].length()]))
                    continue;
                if (cmp > -49 && (nums[j].length() == 1) && (nums[j + 1][0] > nums[j + 1][1]))
                    continue;

                tempStr = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tempStr;
            }
            else if (cmp > 0 && cmp < 49)
            {
                subStr = nums[j].string::substr(0, nums[j + 1].length());
                if ((nums[j + 1].string::compare(subStr) == 0) && (nums[j][nums[j + 1].length()] < nums[j + 1][nums[j + 1].length() - 1]))
                {
                    tempStr = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tempStr;
                }
            }
        }
    }
}

void catNums(string nums[], const size_t size, string& concat)
{
    for(size_t i = 0; i < size; ++i)
    {
        concat += nums[i];
    }
}

void print(string nums[], const size_t size)
{
    cout << "Sorted array: ";
    for(size_t i = 0; i < size; ++i)
    {
        std::cout << nums[i] << "  ";
    }
    cout << endl;
}
