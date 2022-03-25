#include <iostream>
#include <cstring>
#define GRADES_MAX_SIZE 10
#define NAME_MAX_SIZE 50
#define STR_MAX_SIZE 50
using std::string;
using std::cout;
using std::cin;
using std::endl;

struct Student {
    string name;
    unsigned group;
    unsigned grades[GRADES_MAX_SIZE];
};

size_t getStudSize();
void inputStudData(Student* students, size_t size);
void printStudData(Student& student, size_t studNum);
void getUserStr(string& userStr);
void printUserDataIf(Student students[], size_t size, string& str);

int main()
{
    size_t studSize = 10;
    studSize = getStudSize();
    if (studSize == 0)
    {
        cout << "Students count error, try again." << endl;
        exit(1);
    }
    studSize += 1;
    
    Student students[studSize];
    inputStudData(students, studSize);
    
    string userStr;
    getUserStr(userStr);
    
    printUserDataIf(students, studSize, userStr);
    
    return 0;
}

size_t getStudSize()
{
    size_t size;
    cout << "Input students count: ";
    cin >> size;
    return size;    
}

void inputStudData(Student students[], size_t size)
{
    char name[NAME_MAX_SIZE];
    
    for (size_t i = 1; i < size; ++i)
    {
        cout << "\nInput name for student N" << i << ": ";
        cin.ignore();
        cin.getline(name, NAME_MAX_SIZE);
        students[i].name = name;
        
        cout << "Input group for student N" << i << ": ";
        cin >> students[i].group;
        
        cout << "Input grades for student N" << i << ": ";
        for (size_t j = 0; j < GRADES_MAX_SIZE; ++j)
        {
            cin >> students[i].grades[j];
        }
    }
}

void getUserStr(string& userStr)
{
    char str[STR_MAX_SIZE];
    
    cout << "\nInput your string: ";
    cin.ignore();
    cin.getline(str, STR_MAX_SIZE);
    userStr = str;
}

void printUserDataIf(Student students[], size_t size, string& str)
{
    bool find = false;
    size_t len = str.length();
    string subName;
    
    for (size_t i = 1; i < size; ++i)
    {
        subName = students[i].name.substr(students[i].name.length() - len, len);
        if ((subName.string::compare(str) == 0))
        {
            if (find == false)
            {
                cout << "\nStudents who fit the criteria :" << endl;
            }
            find = true;
            printStudData(students[i], i);
        }
    }
    
    if (find == false)
    {
        cout << "\nStudents not found!" << endl;
    }
}

void printStudData(Student& student, size_t studNum)
{
    cout << "\nStudent N" << studNum << endl;
    cout << "Name: " << student.name << endl;
    cout << "Group: " << student.group << endl;
    cout << "Grades: ";
    for (size_t i = 0; i < GRADES_MAX_SIZE; ++i)
    {
        cout << student.grades[i] << " ";
    }
    cout << endl;
}
