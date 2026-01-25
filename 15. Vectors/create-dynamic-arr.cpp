#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size]; // Dynamically allocate array

    int x = 1;

    for (int i=0; i<size; i++) {
        arr[i] = x;
        cout << arr[i] << " ";
        x++;
    }
    cout << endl;

    return 0;
}