#include<iostream>
using namespace std;

void funcInt() {
    int *ptr = new int; // Dynamically allocate single integer
    *ptr = 42;
    cout << "Value: " << *ptr << endl;

    delete ptr; // Free the allocated memory
}

void funcArray() {
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

    delete[] arr; // Free the allocated memory for array
}

int main() {

    funcInt();
    //funcArray();
    return 0;
}