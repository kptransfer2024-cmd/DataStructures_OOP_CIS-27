#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    const static int size = 1000;
    char arr[size];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool empty() {
        return isEmpty();
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        top--;
        return arr[top + 1];
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element exists." << endl;
            return '\0';
        }
        return arr[top];
    }
};


int main() {
    Stack stack;
    string input;

    cout << "Please input String:" << endl;
    getline(cin, input);

    for (char c : input) {
        stack.push(c);
    }

    while (!stack.empty()) {
        cout << stack.pop();
    }

    cout << endl;

    return 0;
}