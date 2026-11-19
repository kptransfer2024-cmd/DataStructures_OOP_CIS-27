#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Queue {
private:
    vector<char> vec;

public:
    bool empty() {
        return vec.empty();
    }

    bool isFull() {
        return (vec.size() >= vec.max_size());
    }

    void enqueue(char value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        vec.push_back(value);
    }

    char dequeue() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return '\0';
        }

        char value = vec.front();
        vec.erase(vec.begin());
        return value;
    }

    char peek() {
        if (empty()) {
            cout << "Queue is empty! No front element exists." << endl;
            return '\0';
        }

        return vec.front();
    }
};

int main() {
    Queue queue;
    string input;

    cout << "Please input String:" << endl;
    getline(cin, input);

    for (char c : input) {
        queue.enqueue(c);
    }

    while (!queue.empty()) {
        char c = queue.dequeue();
        cout << c << c;
    }

    cout << endl;

    return 0;
}
