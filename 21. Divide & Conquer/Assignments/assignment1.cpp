/*
Question 1 : Apply Merge sort to sort an array of Strings. (Assume that all the characters 
in all the Strings are in lowercase). (EASY)

Sample Input 1 : arr = { "sun", "earth", "mars", "mercury" }
Sample Output 1 : arr = { "earth", "mars", "mercury", "sun"}
*/

#include<iostream>
#include<vector>
using namespace std;

void mergeStrs(string arr[], int si, int ei, int mid) {
    vector<string> temp;

    int i = si;
    int j = mid+1;

    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }       
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while (j <= ei)
    {
        temp.push_back(arr[j++]);
    }

    for (int idx = si, x = 0; idx <= ei; idx++) {
        arr[idx] = temp[x++];
    }
}

void mergeSortStrs(string arr[], int si, int ei) {
    //Base Case
    if (si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSortStrs(arr, si, mid);
    mergeSortStrs(arr, mid+1, ei);

    mergeStrs(arr, si, ei, mid);
}

void printStrArr(string arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    string arr[4] = { "sun", "earth", "mars", "mercury" };
    int n = 4;

    mergeSortStrs(arr, 0, n-1);
    printStrArr(arr, n);
    return 0;
}