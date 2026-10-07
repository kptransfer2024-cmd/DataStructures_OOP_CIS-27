#include <iostream>
#include <fstream>
#include "binarySearch.h"
using namespace std;


Common_Alg::Common_Alg() {
    size = 1000;
    data = new int[size];

    ifstream infile("../lab5/array.txt");
        for (int i = 0; i < size; i++) {
        infile >> data[i];
    }

    infile.close();
}

Common_Alg::~Common_Alg() {
    delete[] data;
}

void Common_Alg::bubbleSort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "Array sorted using bubble sort." << endl;
}

void Common_Alg::viewArray() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}

int Common_Alg::binarySearch(int target) {
    bubbleSort();

    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) return mid;
        if (data[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}


// void generateArray(int numbers[], int size) {
//     for (int i = 0; i < size; i++) {
//         numbers[i] = rand() % 1000;
//     }
// }


// int binarySearch(int data[], int size, int target) {
//     int left = 0, right = size - 1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;

//         if (data[mid] == target) return mid;
//         if (data[mid] < target) left = mid + 1;
//         else right = mid - 1;
//     }

//     return -1;
// }

// void bubbleSort(int numbers[], int size) {
//     for (int i = 0; i < size - 1; i++){
//         for (int j = 0; j < size - i - 1; j++){
//             if (numbers[j] > numbers[j + 1]){
//                 int temp = numbers[j];
//                 numbers[j] = numbers[j + 1];
//                 numbers[j + 1] = temp;
//             }
//         }
//     }
// }



// void viewArray(int numbers[], int size) {
//     for (int i = 0; i < size; i++) {
//         cout << numbers[i] << " ";
//     }
//     cout << endl;
// }


