#include <iostream>
using std::cout;
using std::endl;

template <typename T>
struct Node {
    T data;
    struct Node* next;
};

// Floyd’s slow and fast pointers algorithm
template <typename T>
bool isLooped(Node<T>* head)
{
    Node<T>* slow = head;
    Node<T>* fast = head;
 
    while (slow && fast && fast->next) 
    {
        slow = slow->next; // 1 step per iteration
        fast = fast->next->next; // 2 steps per iteration
        
        // loop found condition
        if (slow == fast) 
            return true;
    }
    
    return false;
}

template <typename T>
void push_back(Node<T>*& head, T newData)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    
    Node<T>* temp = head;
    while (temp->next)
        temp = temp->next;
    
    temp->next = newNode;
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
    
    // creat loop
    head->next->next->next->next->next->next = head->next->next;
    
    if (isLooped(head))
        cout << "Found loop in given list!" << endl;
    else
        cout << "There are no loop in given list!" << endl;

    return 0;
}
