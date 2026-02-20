#include<iostream>
using namespace std;

int binSearch(int *arr, int n, int key) {
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int key = 3;

    int index = binSearch(arr, n, key);

    if (index != -1) {
        cout << "Element found at index: " << index << endl; // The binary search algorithm has a time complexity of O(log n) because it halves the search space with each iteration.
    }
    else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}