#include <iostream>
#include "floatvalues.h"
using namespace std;

int main() {
    FloatValues floatValues;
    cout << "Float Values loaded:" << endl;
    floatValues.displayValues();
    cout << endl;
    floatValues.sumAllValues();
    cout << endl;
    floatValues.highestValue();
    cout << endl;
    floatValues.lowestValue();
    cout << endl;
    floatValues.meanAverage();
    cout << endl;
    floatValues.appendToFile();
    cout << endl;

    FloatValues floatValues_appended;
    cout << "see the Float Values after appending to file:" << endl;
    floatValues_appended.displayValues();
    cout << endl;

    return 0;
}