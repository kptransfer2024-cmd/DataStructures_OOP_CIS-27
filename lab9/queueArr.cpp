#include <iostream>
#include <cstdlib>
using namespace std;
 
// Define the default capacity of a queue
#define SIZE 1000
 
class Queue
{
    char *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
 
public:
    Queue(int size = SIZE);     // constructor
    ~Queue();                   // destructor
 
    char dequeue();
    void enqueue(char x);
    char peek();
    int size();
    bool isEmpty();
    bool isFull();
};
 
// Constructor to initialize a queue
Queue::Queue(int size)
{
    arr = new char[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 
// Destructor to free memory allocated to the queue
Queue::~Queue() {
    delete[] arr;
}
 
// Utility function to dequeue the front element
char Queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Queue is empty. " << endl;
        exit(EXIT_FAILURE);
    }
 
    char x = arr[front];
 
    front = (front + 1) % capacity;
    count--;
 
    return x;
}
 
// Utility function to add an item to the queue
void Queue::enqueue(char item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Queue is full. " << endl;
        exit(EXIT_FAILURE);
    }
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
 
// Utility function to return the front element of the queue
char Queue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty. " << endl;
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
 
// Utility function to return the size of the queue
int Queue::size() {
    return count;
}
 
// Utility function to check if the queue is empty or not
bool Queue::isEmpty() {
    return (size() == 0);
}
 
// Utility function to check if the queue is full or not
bool Queue::isFull() {
    return (size() == capacity);
}
 
int main()
{
    string input;

    cout << "Please input String: ";
    cin >> input;

    Queue q(input.length());

    for (char c : input) {
        q.enqueue(c);
    }

    while (!q.isEmpty()) {
        char c = q.dequeue();
        cout << c << c;
    }

    cout << endl;

    return 0;
}

