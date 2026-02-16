/*
Question 2 : For a given integer array of size N. You have to find all the occurrences
(indices) of a given element (Key) and print them.

Use a recursive function to solve this problem.

Sample Input : arr[ ] = {3, 2, 4, 5, 6, 2, 7, 2, 2}, key = 2
Sample Output : 1 5 7 8
*/

#include<iostream>
using namespace std;

void allOccurences(int arr[], int i, int n, int key) {

    //Base Case
    if (i == n) {
        return;
    }

    if (arr[i] == key) {
        cout << i << " ";
    }

    allOccurences(arr, i+1, n, key);
}

int main() {
    int arr[9] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int key = 2;
    int n = 9;

    allOccurences(arr, 0, n, key);
    return 0;
}