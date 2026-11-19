#include <iostream>
#include "binarySearch.h"
using namespace std;


int main() {
    Common_Alg c_alg;

    int target;

    cout << "Enter a number to search (1-1000): ";
    cin >> target;

    int result = c_alg.binarySearch(target);

    if (result == -1) {
        cout << "Number not found in the array." << endl;
    } else {
        cout << "Number found at index: " << result << endl;
    }


    return 0;
}


