#include<iostream>
using namespace std;

int search(int arr[], int si, int ei, int target) {
    //Base Case
    if (si > ei) {
        return -1;
    }

    int mid = (si + ei) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[si] <= arr[mid]) { //L1
        if (arr[si] <= target && target <= arr[mid]) {
            return search(arr, si, mid-1, target); //left half
        } else {
            return search(arr, mid+1, ei, target); //right half
        }
    } else { //L2
        if (arr[mid] <= target && target <= arr[ei]) {
            return search(arr, mid+1, ei, target); //right half
        } else {
            return search(arr, si, mid-1, target); //left half
        }
    }
}

int main() {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    cout << "Idx: " << search(arr, 0, n-1, 0) << endl; //4
    return 0;
}