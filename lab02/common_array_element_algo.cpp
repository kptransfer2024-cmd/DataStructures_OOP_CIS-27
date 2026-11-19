#include <iostream>

using namespace std;


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void nodeConnectionIterator(int arr[], int n) {
    int it = 0;
    int end = n;
    if (it == end){
        cout << endl;
        return;
    }
    cout << arr[it] << " ";
    nodeConnectionIterator(arr + 1, n - 1);
}

void linearSearch(int arr[], int n, int key) {
    bool is_found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Value " << key << " is found at index " << i << endl;
            is_found = true;
        }
    }
    if (!is_found) {
        cout << "Value " << key << " not found in the array." << endl;
    }
}

void highestValue(int arr[], int n){
    int highest = arr[0];
    for (int i=1; i < n; i++){
        if (arr[i] > highest){
            highest = arr[i];
        }
    }
    cout << "The highest value is: " << highest << endl;
}

void middleIndex(int arr[], int n){
    int mid_i;
    if (n % 2 == 0){
        mid_i = n / 2;
        cout << "The middle index is: " << mid_i << endl;
    } else {
        mid_i = (n -1) / 2;
        cout << "The middle index is: " << mid_i << endl;
    }
}


void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    printArray(arr, n);
}

void meanAverage(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    float mean = static_cast<float>(sum) / n;
    cout << "The mean average is: " << mean << endl;
}

void medianAverage(int arr[], int n){
    
    int sorted_arr[n];
    for (int i = 0; i < n; i++){
        sorted_arr[i] = arr[i];
    }
    bubbleSort(sorted_arr, n);

    float median;
    if (n % 2 == 1){
        median = sorted_arr[(n - 1) / 2];
    }
    else{
        median = (static_cast<float>(sorted_arr[n/2 - 1]) + static_cast<float>(sorted_arr[n/2])) / 2;
    }
    cout << "The median average is: " << median << endl;
}

int main() {
    int arr[] = {11, 22, 33, 44, 55, 66, 55, 44, 99, 100};
    int n = sizeof(arr) / sizeof(arr[0]);


    medianAverage(arr, n);
    return 0;
}

