#include <iostream>
#include <iterator>
#include <list>
using std::list;
using std::cout;
using std::endl;

template <typename T>
void fillList(list<T>& lst);
template <typename T>
void printList(list<T>& lst);
template <typename T>
T getMiddleNodeValue(list<T>& lst);

int main()
{
    list<int> lst;
    fillList(lst);
    
    printList(lst);
    cout << "\nMiddle node value is: " << getMiddleNodeValue(lst);

    return 0;
}

template <typename T>
void fillList(list<T>& lst)
{
    T temp;
    
    for (size_t i = 0; i < 10; ++i)
    {
        cout << "Print node " << i << " value: ";
        std::cin >> temp;
        lst.push_back(temp);
    }
}

template <typename T>
void printList(list<T>& lst)
{
    size_t currentNode = 0;
    
    cout << "\nYour list values: " << std::endl;
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        cout << "Node in index " << currentNode << " have value: " << *it << std::endl;
        ++currentNode;
    }
}

template <typename T>
T getMiddleNodeValue(list<T>& lst)
{
    size_t size = lst.size();

    auto it = lst.begin();
    advance(it, (size / 2) - 1);
    return (*it);
}
