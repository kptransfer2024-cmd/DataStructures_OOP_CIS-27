#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
private:
    vector<char> vec;

public:
    bool empty() {
        return vec.empty();
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
        return;
        }
        vec.push_back(value);
    }


    bool isFull() {
        return (vec.size() >= vec.max_size());
    }

    char pop() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }

        char value = vec.back();
        vec.pop_back();
        return value;
    }

    char peek() {
        if (empty()) {
            cout << "Stack is empty! No top element exists." << endl;
            return '\0';
        }

        return vec.back();
    }
};


int main() {
    Stack stack;
    string input;

    cout << "Please input String:" << endl;
    getline(cin, input);

    cout << "Vector is dynamic, so the stack can grow." << endl;
    for (char c : input) {
        stack.push(c);
    }

    while (!stack.empty()) {
        cout << stack.pop();
    }

    cout << endl;

    return 0;
}
