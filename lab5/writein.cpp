#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    ofstream outfile("array.txt");
    if (!outfile.is_open()) {
        cerr << "Failed to open file for writing.\n";
        return 1;
    }


    for (int i = 0; i < size; i++) {
        outfile << arr[i] << " ";
        // cout << arr[i] << " ";
    }

    outfile.close();

    ifstream infile("array.txt");

    for (int i = 0; i < size; i++) {
        infile >> arr[i];
    }

    for (int i = 0; i < size; i++) {
        cout << 10 * arr[i] << " ";
    }

    infile.close();

    return 0;
}

