#include <iostream>
#include <fstream>
#include "floatvalues.h"
using namespace std;

FloatValues::FloatValues() {
    size = 0;
    mean_average = 0;
    sum_of_values = 0;
    numbers = new float[100] {};

    ifstream infile("floatvalues-1.txt");
    while (size < 100 && infile >> numbers[size]) {
    size++;
    }

    infile.close();
}


FloatValues::~FloatValues() {
    delete[] numbers;
}


void FloatValues::displayValues() {
    cout << "let's see the Float Values stored in the .txt: " << endl;
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << endl;
    }
}


void FloatValues::sumAllValues(){
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    cout << "Sum of all values: " << sum << endl;
    sum_of_values = sum;
};


void FloatValues::highestValue(){
    float highest = numbers[0];
    int location = 0;
    for (int i = 1; i < size; i++){
        if (numbers[i] > highest){
            highest = numbers[i];
            location = i;
        }
    }
    cout << "The highest value is: " << highest << endl;
    cout << "The index of the highest value is: " << location << endl;
}


void FloatValues::lowestValue(){    
    float lowest = numbers[0];
    int location = 0;
    for (int i = 1; i < size; i++){
        if (numbers[i] < lowest){
            lowest = numbers[i];
            location = i;
        }
    }
    cout << "The lowest value is: " << lowest << endl;
    cout << "The index of the lowest value is: " << location << endl;
}


void FloatValues::meanAverage(){
    float mean = sum_of_values / size;
    cout << "The mean average is: " << mean << endl;
    mean_average = mean;
}


void FloatValues::appendToFile(){
    ofstream outfile("floatvalues-1.txt", ios::app);

    outfile << sum_of_values << endl;
    outfile << mean_average << endl;

    cout << "sum and mean average appended to file!" << endl;
    outfile.close();
}

