#include<iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changeArr(int arr[], int n, int i) {
    if (i == n)
    {
        printArr(arr , n);
        return;
    }
    
    arr[i] = i + 1; // Make a choice

    changeArr(arr, n, i + 1); // Recursion

    arr[i] -= 2; // Backtrack (undo the choice)
}

int main() {
    int arr[5] = {0};
    int n = 5;

    changeArr(arr, n, 0);
    printArr(arr, n); // Final array after full backtracking
    return 0;
}