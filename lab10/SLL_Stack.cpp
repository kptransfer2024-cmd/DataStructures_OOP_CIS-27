#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};


class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }


    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }


    void push(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }


    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }


    bool empty() {
        return top == nullptr;
    }


    char peek() {
        return top->data;
    }
};



int main() {
    Stack s;
    string input;

    cout << "Please input String:" << endl;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        s.push(input[i]);
    }

    while (!s.empty()) {
        cout << s.peek();
        s.pop();
    }

    cout << endl;

    return 0;
}
