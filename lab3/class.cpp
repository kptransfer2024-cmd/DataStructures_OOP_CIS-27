#include <iostream>
#include <cstdlib>

using namespace std;

class studentIDList {
public:
    studentIDList();
    void show_numbers();

private:
    int numbers[1000];
};


studentIDList::studentIDList() {
    for (int i = 0; i < 1000; i++) {
        numbers[i] = rand() % 1000 + 1;
    }
}


void studentIDList::show_numbers() {
    for (int i = 0; i < 1000; i++) {
        cout << numbers[i] << endl;
    }
}


int main() {
    studentIDList student_list1;
    student_list1.show_numbers();

    return 0;
}