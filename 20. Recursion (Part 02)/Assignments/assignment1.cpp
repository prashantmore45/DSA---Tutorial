/*
Question 1 : Write a recursive function to perform Binary Search.

Input : arr[ ] = {1, 2, 3, 4, 5, 6, 7}, n = 7, key = 5
Output : 4 (index of key)

*Use the starting index & ending index logic used in rotated, sorted array Qs.
*/

#include<iostream>
using namespace std;

int binSearch(int arr[], int start, int end, int key) {
    //Base Case
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key) {
        return mid;
    }

    if (key < arr[mid]) {
        return binSearch(arr, start, mid - 1, key);
    } else {
        return binSearch(arr, mid + 1, end, key);
    }
}

int main() {
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int key = 5;

    cout << binSearch(arr, 0, 6, key) << endl;
    return 0;
}