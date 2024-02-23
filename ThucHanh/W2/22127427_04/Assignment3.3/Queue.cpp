#include "Queue.h"

void Queue::init(int n)
{
    capacity = n;
    p_head = p_tail = NULL;
}

void Queue::enqueue(int x)
{
    Node* newNode = new Node;
    newNode -> key = x;

    if(isFull())
    {
        cout << "\nQueue is full.";
        return;
    }

    if(p_head == NULL)
    {
        p_head = p_tail = newNode;
        return;
    }

    p_tail -> p_next = newNode;
    p_tail = newNode;
    p_tail -> p_next = NULL;
    ++num;
}

int Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "\nQueue is empty.";
        return 0;
    }

    Node* temp = p_head;
    p_head = temp -> p_next;
    int x = temp -> key;

    delete temp;
    --num;

    return x;
}

Node* Queue::peek()
{
    return p_head;
}

bool Queue::isEmpty()
{
    if(p_head == NULL)
    {
        return true;
    }
    return false;
}

bool Queue::isFull()
{
    if(num == capacity)
    {
        return true;
    }
    return false;
}

void Queue::clear()
{
    while(num != 0)
    {
        dequeue();
    }
}