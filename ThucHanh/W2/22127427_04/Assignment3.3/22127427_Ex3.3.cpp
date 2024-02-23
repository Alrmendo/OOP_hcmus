#include "Queue.h"

int main()
{
    Queue q;
    int n;
    int num = 0;

    cout << "\nEnter queue capacity: ";
    cin >> n;

    q.init(n);
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cout << "\nEnter value " << i << " : ";
        cin >> temp;
        q.enqueue(temp);
    }

    Node* p = q.p_head;
    cout << "\nQueue: ";
    while (p != NULL)
    {
        cout << p -> key << " ";
        p = p -> p_next;
    }

    cout << "\ndequeue: ";
    if (!q.isEmpty()) 
    {
        cout << q.dequeue();
    } 
    else 
    {
        cout << "Queue is empty.";
    }


    cout << "\nPeek: ";
    if (!q.isEmpty()) 
    {
        cout << q.peek() -> key;
    } 
    else 
    {
        cout << "Queue is empty.";
    }

    cout << "\nNew queue: ";
    p = q.p_head;
    while (p != NULL)
    {
        cout << p -> key << " ";
        p = p -> p_next;
    }

    cout << "\nClearing the queue...";
    q.clear();
    cout << "\nQueue cleared.";

    return 0;
}
