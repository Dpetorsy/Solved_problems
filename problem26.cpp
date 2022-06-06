#include <iostream>
using std::cout;
using std::endl;

template <typename T>
struct Node {
    T data;
    struct Node* next;
    struct Node* prev;
};

template <typename T>
Node<T>* getTail(Node<T>* head)
{
    auto tail = head;
    
    if (!head)
        return nullptr;

    while (tail->next)
        tail = tail->next;
        
    return tail;
}

template <typename T>
size_t getListSize(Node<T>* head)
{
    auto it = head;
    size_t size = 0;
    
    while (it)
    {
        it = it->next;
        ++size;
    }
    
    return size;
}

template <typename T>
void reverseList(Node<T>*& head)
{
    auto tail = getTail(head);
    auto size = getListSize(head);
    
    if (!head or !tail or size <= 1)
        return;
        
    auto it = head;
    while (it)
    {
        auto temp = it;
        it = it->next;
        
        auto temp1 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp1;
    }

    head = tail;
}

template <typename T>
void push_back(Node<T>*& head, T newData)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    
    if (head == nullptr)
    {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }
    
    auto it = head;
    while (it->next)
        it = it->next;
    
    newNode->prev = it;
    it->next = newNode;
}

template <typename T>
void printList(Node<T>* head)
{
    auto it = head;
    
    cout << "List nodes values: ";
    while (it)
    {
        cout << it->data << " ";
        it = it->next;
    }
    cout << endl << endl;
}

int main()
{
    Node<int>* head = nullptr;
    
    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    push_back(head, 4);
    push_back(head, 5);
    push_back(head, 6);
    push_back(head, 7);
    
    printList<int>(head);
    
    cout << "Reversing list..." << endl << endl;
    reverseList(head);
    
    printList<int>(head);
    
    return 0;
}
