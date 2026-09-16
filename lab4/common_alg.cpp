#include <iostream>
using namespace std;

class Common_Alg {

private:
    int numbers[1000];

public:    
    Common_Alg(){
        for (int i = 0; i < 1000; i++) {
            numbers[i] = rand() % 1000 + 1;
        }
    }



    void show_numbers(){
    for (int i = 0; i < 1000; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
};


    void sumAllValues(){
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += numbers[i];
    }
    cout << "Sum of all values: " << sum << endl;
};


    void showOddNumbers(){
    for (int i = 0; i < 1000; i++) {
        if (numbers[i] % 2 == 1) {
            cout << numbers[i] << " ";
        } 
    }
    cout << endl;
};


    void showEvenNumbers(){
    for (int i = 0; i < 1000; i++) {
        if (numbers[i] % 2 == 0) {
            cout << numbers[i] << " ";
        } 
    }
    cout << endl;
};


    void linearSearch(int key){
    bool is_found = false;
    for (int i = 0; i < 1000; i++) {
        if (numbers[i] == key) {
            cout << "Value " << key << " is found at index " << i << endl;
            is_found = true;
        }
    }
    if (!is_found) {
        cout << "Value " << key << " not found in the array." << endl;
    }
}
    

    void middleValue(){
    int mid_i;
    mid_i = 1000 / 2;
    cout << "The values in the middle are: " << endl;
    cout << numbers[mid_i - 1] << " and " << numbers[mid_i] << endl;
}    


    void firstValue(){
    int first_i = 0;
    cout << "The first value is: " << numbers[first_i] << endl;
}


    void lastValue(){
    int last_i = 1000 - 1;
    cout << "The last value is: " << numbers[last_i] << endl;
}

    void highestValue(){
    int highest = numbers[0];
    int location = 0;
    for (int i = 1; i < 1000; i++){
        if (numbers[i] > highest){
            highest = numbers[i];
            location = i;
        }
    }
    cout << "The highest value is: " << highest << endl;
    cout << "The index of the highest value is: " << location << endl;
}


    void lowestValue(){    
    int lowest = numbers[0];
    int location = 0;
    for (int i = 1; i < 1000; i++){
        if (numbers[i] < lowest){
            lowest = numbers[i];
            location = i;
        }
    }
    cout << "The lowest value is: " << lowest << endl;
    cout << "The index of the lowest value is: " << location << endl;
}


    void bubbleSort(){
    int sorted_numbers[1000];
    for (int i = 0; i < 1000; i++) {
        sorted_numbers[i] = numbers[i];
    }
    for (int i = 0; i < 1000 - 1; i++){
        for (int j = 0; j < 1000 - i - 1; j++){
            if (sorted_numbers[j] > sorted_numbers[j + 1]){
                int temp = sorted_numbers[j];
                sorted_numbers[j] = sorted_numbers[j + 1];
                sorted_numbers[j + 1] = temp;
            }
        }
    }
    
    cout << "The sorted array is: [ ";
    for (int i = 0; i < 1000 - 1; i++){
        cout << sorted_numbers[i] << " ";
    }
    cout << sorted_numbers[1000 - 1] << "] " << endl;
};


    void meanAverage(){
    int sum = 0;
    for (int i = 0; i < 1000; i++){
        sum += numbers[i];
    }
    float mean = static_cast<float>(sum) / 1000;
    cout << "The mean average is: " << mean << endl;
}

};


int main(){
    cout << "-------- ---------------- ---------" << endl;
    cout << "-------- Common Algorithm ---------" << endl;
    cout << "-------- ---------------- ---------" << endl;
    cout << endl;

    cout << "Do you want to generate a random array of 1000 integers between 1 - 1000? (y/n): ";
    char choice;
    cin >> choice;
    cout << endl;

    if (choice == 'n' || choice == 'N' || choice == 'no' || choice == 'No' || choice == 'NO') {
        cout << "You chose not to generate a random array." << endl;
        cout << "See you next time!" << endl;
    }

    if (choice == 'y' || choice == 'Y' || choice == 'yes' || choice == 'Yes' || choice == 'YES') {
        Common_Alg common_alg_1;
        cout << "A array of 1000 random integers generated." << endl;
        cout << endl;

        cout << "Please select an option from the menu below:" << endl;
        cout << "1. Show all numbers" << endl;
        cout << "2. Sum of all values" << endl;
        cout << "3. Show odd numbers" << endl;
        cout << "4. Show even numbers" << endl;
        cout << "5. Linear search for a value" << endl;
        cout << "6. Show middle value" << endl;
        cout << "7. Show first value" << endl;
        cout << "8. Show last value" << endl;
        cout << "9. Show highest value" << endl;
        cout << "10. Show lowest value" << endl;
        cout << "11. Sort the array using bubble sort" << endl;
        cout << "12. Calculate mean average" << endl;
        cout << endl;

        int option;
        cout << "Enter 1-12: ";
        cin >> option;

        switch (option) {
            case 1:
                common_alg_1.show_numbers();
                break;
            case 2:
                common_alg_1.sumAllValues();
                break;
            case 3:
                common_alg_1.showOddNumbers();
                break;
            case 4:
                common_alg_1.showEvenNumbers();
                break;
            case 5:
                int key;
                cout << "Enter a value to search for: ";
                cin >> key;
                common_alg_1.linearSearch(key);
                break;
            case 6:
                common_alg_1.middleValue();
                break;
            case 7:
                common_alg_1.firstValue();
                break;
            case 8:
                common_alg_1.lastValue();
                break;
            case 9:
                common_alg_1.highestValue();
                break;
            case 10:
                common_alg_1.lowestValue();
                break;
            case 11:
                common_alg_1.bubbleSort();
                break;
            case 12:
                common_alg_1.meanAverage();
                break;
            default:
                cout << "Please enter a number between 1 and 12." << endl;
        }
    } else {
        cout << "Exiting the program." << endl;
    }

    return 0;
}