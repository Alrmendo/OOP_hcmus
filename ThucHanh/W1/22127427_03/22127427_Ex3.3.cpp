#include "header3.3.h"

void init(LinkedListQueue& q, int capacity)
{
    q.head = NULL;
    q.tail = NULL;
    q.capacity = capacity;
    q.num = 0;
}

void enqueue(LinkedListQueue& q, int x)
{
    if(q.num < q.capacity)
    {
        Node* newNode = new Node;
        newNode -> data = x;
        newNode -> next = NULL;
        if(q.head == NULL)
        {
            q.head = newNode;
            q.tail = newNode;
        }
        q.num ++;
    }
    else
    {
        cout << "Queue is full. Cannot enqueue " << x << endl;
    }
}

int dequeue(LinkedListQueue& q) 
{
    if (q.head != nullptr) 
    {
        int result = q.head -> data;
        Node* temp = q.head;
        q.head = q.head -> next;
        delete temp;
        q.num --;
        return result;
    } 
    else 
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    }
}

int peek(const LinkedListQueue& q) 
{
    if (q.head != nullptr) 
    {
        return q.head->data;
    } 
    else 
    {
        cout << "Queue is empty. Cannot peek." << endl;
        return -1; 
    }
}

bool isEmpty(const LinkedListQueue& q) 
{
    return q.num == 0;
}

bool isFull(const LinkedListQueue& q) 
{
    return q.num == q.capacity;
}

void clear(LinkedListQueue& q) 
{
    while (q.head != nullptr) 
    {
        Node* temp = q.head;
        q.head = q.head -> next;
        delete temp;
    }
    q.tail = nullptr;
    q.num = 0;
}
