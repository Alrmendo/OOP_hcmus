#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct LinkedListQueue
{
    Node* head;
    Node* tail;
    int capacity;
    int num;
};

void init(LinkedListQueue& q, int capacity);
void enqueue(LinkedListQueue& q, int x);
int dequeue(LinkedListQueue& q); 
int peek(const LinkedListQueue& q);
bool isEmpty(const LinkedListQueue& q); 
bool isFull(const LinkedListQueue& q); 
void clear(LinkedListQueue& q); 
