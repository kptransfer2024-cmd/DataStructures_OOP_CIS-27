#include <iostream>
#include <string>
using namespace std;


struct Node {
    char data;
    Node* next;
    Node* prev;
};


class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }



    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }


    void enqueue(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }


    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        else {
            front->prev = nullptr;
        }

        delete temp;
    }


    bool empty() {
        return front == nullptr;
    }


    char peek() {
        return front->data;
    }
};


int main() {
    Queue q;
    string input;

    cout << "Please input String:" << endl;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        q.enqueue(input[i]);
        q.enqueue(input[i]);
    }

    while (!q.empty()) {
        cout << q.peek();
        q.dequeue();
    }

    cout << endl;

    return 0;
}
