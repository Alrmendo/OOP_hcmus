#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    Node* p_next;
};

class Queue
{
public:
    //variables
    Node* p_head;
    Node* p_tail;
    int capacity;
    int num;

    //functions
    void init(int);
    void enqueue(int);
    int dequeue();
    Node* peek();
    bool isEmpty();
    bool isFull();
    void clear();
};

#endif

