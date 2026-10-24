#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


void generateArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = static_cast<float>(1.0f + (rand()) / static_cast<double>(RAND_MAX) * 999.0);
    }
}


void displayArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void loadMostlySortedArray(float arr[], int size, bool descending = true) {

    ifstream infile;
    if (descending) {
        infile.open("descending_mostly_sorted.txt");
        cout << "Descending mostly sorted array loaded! " << endl;
    }
    else {
        infile.open("ascending_mostly_sorted.txt");
        cout << "Ascending mostly sorted array loaded! " << endl;
    }

    char comma;

    for (int i = 0; i < size; i++) {
        infile >> arr[i];

        if (i < size - 1) {
            infile >> comma;
        }
    }

    infile.close();
}


void bubbleSort(float arr[], int size) {
    int swap_count = -1;
    int i = 0;
    while (!(swap_count == 0)) {
        swap_count = 0;
        int j = 0;
        while (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swap_count++;
            } 
            j++;
        }
        i++;
    }
}


void insertionSort(float arr[], int size) {
    for (int i = 1; i < size; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void selectionSort(float arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            float temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
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

    float pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    float temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}


void shellSort(float arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            float temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


void heapify(float arr[], int size, int i) {
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        float temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

void heapSort(float arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);    
    } 
    for (int i = size - 1; i > 0; i--) {
        float temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}


int main() {

    const int arr_size = 1000;
    cout << "array size is now: " << arr_size << endl;
    cout << "For an array with " << arr_size << " random floats: ";
    cout << endl;
    cout << endl;

    float arr1[arr_size];
    float arr2[arr_size];
    float arr3[arr_size];

    srand(static_cast<unsigned int>(time(nullptr)));

    
    generateArray(arr1, arr_size);

    clock_t start1 = clock();

    bubbleSort(arr1,arr_size);

    clock_t end1 = clock();

    double timeTaken1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Bubble Sort execution time: " << timeTaken1 * 1000 << " milliseconds" << endl;

    cout << endl;    


    generateArray(arr2, arr_size);
    
    clock_t start2 = clock();

    insertionSort(arr2, arr_size);

    clock_t end2 = clock();

    double timeTaken2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Insertion Sort execution time: " << timeTaken2 * 1000 << " milliseconds" << endl;
    
    cout << endl;


    generateArray(arr3, arr_size);

    clock_t start3 = clock();

    quickSort(arr3, 0, arr_size - 1);

    clock_t end3 = clock();

    double timeTaken3 = double(end3 - start3) / CLOCKS_PER_SEC;
    cout << "Quick Sort execution time: " << timeTaken3 * 1000 << " milliseconds" << endl;
    
    cout << endl;
    cout << endl;


    float arr4[arr_size];
    float arr5[arr_size];
    float arr6[arr_size];

    loadMostlySortedArray(arr4, arr_size, true);
    clock_t start4 = clock();

    bubbleSort(arr4,arr_size);

    clock_t end4 = clock();

    double timeTaken4 = double(end4 - start4) / CLOCKS_PER_SEC;
    cout << "Bubble Sort execution time: " << timeTaken4 * 1000 << " milliseconds" << endl;

    cout << endl;    

    loadMostlySortedArray(arr5, arr_size, true);
    clock_t start5 = clock();

    insertionSort(arr5, arr_size);

    clock_t end5 = clock();

    double timeTaken5 = double(end5 - start5) / CLOCKS_PER_SEC;
    cout << "Insertion Sort execution time: " << timeTaken5 * 1000 << " milliseconds" << endl;
    
    cout << endl;


    loadMostlySortedArray(arr6, arr_size, true);
    clock_t start6 = clock();

    quickSort(arr6, 0, arr_size - 1);

    clock_t end6 = clock();

    double timeTaken6 = double(end6 - start6) / CLOCKS_PER_SEC;
    cout << "Quick Sort execution time: " << timeTaken6 * 1000 << " milliseconds" << endl;
    
    cout << endl;
    cout << endl;



    float arr7[arr_size];
    float arr8[arr_size];
    float arr9[arr_size];

    loadMostlySortedArray(arr7, arr_size, false);
    clock_t start7 = clock();

    bubbleSort(arr7,arr_size);

    clock_t end7 = clock();

    double timeTaken7 = double(end7 - start7) / CLOCKS_PER_SEC;
    cout << "Bubble Sort execution time: " << timeTaken7 * 1000 << " milliseconds" << endl;

    cout << endl;    

    loadMostlySortedArray(arr8, arr_size, false);
    clock_t start8 = clock();

    insertionSort(arr8, arr_size);

    clock_t end8 = clock();

    double timeTaken8 = double(end8 - start8) / CLOCKS_PER_SEC;
    cout << "Insertion Sort execution time: " << timeTaken8 * 1000 << " milliseconds" << endl;
    
    cout << endl;


    loadMostlySortedArray(arr9, arr_size, false);
    clock_t start9 = clock();

    quickSort(arr9, 0, arr_size - 1);

    clock_t end9 = clock();

    double timeTaken9 = double(end9 - start9) / CLOCKS_PER_SEC;
    cout << "Quick Sort execution time: " << timeTaken9 * 1000 << " milliseconds" << endl;
    
    cout << endl;
    cout << endl;

    
    return 0;
}
