#ifndef FLOATVALUES_H
#define FLOATVALUES_H

class FloatValues {
private:
    int size;
    float mean_average;
    float sum_of_values;
    float* numbers;

public:
    FloatValues();
    ~FloatValues();

    void displayValues();
    void sumAllValues();
    void highestValue();
    void lowestValue();
    void meanAverage();
    void appendToFile();
};

#endif