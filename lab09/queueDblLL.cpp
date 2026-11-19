#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Enqueue adds an element to the rear of the queue
    void enqueue(int value)
    {
        Node* newNode = new Node; // Create a new node

        (*newNode).data = value; // pass the value to the new node
        (*newNode).next = NULL; // first set the next pointer of the new node to NULL
        (*newNode).prev = rear; // set the new node's previous pointer to the current rear

        if (front == NULL) // If the queue is empty, set both front and rear to the new node
        {
            front = newNode;
            rear = newNode;
        }
        else // otherwise, link the new node to the current rear and update the rear pointer
        {
            (*rear).next = newNode;
            rear = newNode;
        }
    }

    // Dequeue removes the element at the front of the queue
    void dequeue()
    {
        if (front == NULL) // Queue is empty
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front; // Store the front node in a temporary variable

        cout << "Removed: " << (*temp).data << endl; // Print the value of the removed node

        front = (*front).next; // Move the front pointer to the next node

        if (front == NULL) // If the queue is now empty (had only one element), set rear to NULL
            rear = NULL;
        else
            (*front).prev = NULL; // Set the previous pointer of the new front node to NULL

        delete temp; // Free the memory of the removed node
    }

    void display()
    {
        Node* temp = front;

        cout << "Queue: ";

        while (temp != NULL)
        {
            cout << (*temp).data << " ";
            temp = (*temp).next;
        }

        cout << endl;
    }
};

int main()
{
    return 0;
}