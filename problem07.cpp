#include <iostream>
#include <string>
#define GRADES_MAX_SIZE 10
#define NAME_MAX_SIZE 50
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
void sortByAVG(double avgs[], Student students[], size_t size);
void getAVG(double avgs[], Student stud[], size_t size);

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
    
    double avgs[studSize];
    sortByAVG(avgs, students, studSize);
    
    cout << "\nStudents sorted by avg : " << endl;
    for (size_t i = 1; i < studSize; ++i)
    {
        printStudData(students[i], i);
        cout << "Average of grades: " << avgs[i] << endl;
    }
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

void sortByAVG(double avgs[], Student students[], size_t size)
{
    Student tempStud;
    double tempAVG = 5;
    
    getAVG(avgs, students, size);
    
    for(size_t i = 1; i < size; ++i)
    {
        for(size_t j = 1; j < size - i; ++j)
        {
            if (avgs[j] > avgs[j + 1])
            {
                tempStud = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tempStud;
                
                tempAVG = avgs[j];
                avgs[j] = avgs[j + 1];
                avgs[j + 1] = tempAVG;
            }
        }
    }
}

void getAVG(double avgs[], Student stud[], size_t size)
{
    double sum = 0;
    
    for(size_t i = 1; i < size; ++i)
    {
        sum = 0;
        for(size_t j = 0; j < GRADES_MAX_SIZE; ++j)
        {
            sum += stud[i].grades[j];
        }
        avgs[i] = sum / GRADES_MAX_SIZE;
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
