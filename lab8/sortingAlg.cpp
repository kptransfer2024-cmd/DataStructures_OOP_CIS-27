#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void displayArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void merge(float arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    float Left[n1];
    float Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];


    int i = 0;
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // for (; i < n1 && j < n2; k++) {
    //         if (Left[i] <= Right[j]) {
    //             arr[k] = Left[i];
    //             i++;
    //         }
    //         else {
    //             arr[k] = Right[j];
    //             j++;
    //     }
    // }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // for (; i < n1; k++) {
    //     arr[k] = Left[i];
    //     i++;
    // }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
    
    // for (; j < n2; k++) {
    //     arr[k] = Right[j];
    //     j++;
    // }
}


void mergeSort(float arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}


void quickSort(float arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}



int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int arr_size = 1000;
    float arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = static_cast<float>(rand() % arr_size) / 1.234321;
    }

    // cout << "Original array: ";
    // displayArray(arr, arr_size);

    clock_t start = clock();

    mergeSort(arr, 0, arr_size - 1);

    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    // cout << "Merge Sort execution time: " << timeTaken << " seconds" << endl;

    
    
    clock_t start1 = clock();

    quickSort(arr, 0, arr_size - 1);

    clock_t end1 = clock();

    double timeTaken1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Quick Sort execution time: " << timeTaken << " seconds" << endl;
    
    cout << endl;
    cout << endl;


    // cout << "Sorted array:   ";
    // displayArray(arr, arr_size);

    return 0;
}
