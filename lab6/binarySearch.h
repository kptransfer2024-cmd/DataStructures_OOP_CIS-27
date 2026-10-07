#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

// void generateArray(int numbers[], int size);

// int binarySearch(int data[], int size, int target);

// void bubbleSort(int numbers[], int size);

// void viewArray(int numbers[], int size);

class Common_Alg {
private:
    int* data;
    int size;

public:
    Common_Alg();
    ~Common_Alg();

    void bubbleSort();
    void viewArray();
    int binarySearch(int target);
};

#endif