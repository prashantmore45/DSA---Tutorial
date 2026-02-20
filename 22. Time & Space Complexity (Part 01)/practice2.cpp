#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) {
            cout << arr[i] << " " << arr[j] << endl; // This nested loop iterates through all unique pairs of elements in the array, resulting in a time complexity of O(n^2) since it depends on the size of the array.
        }
    }
    
    return 0;
}