/*
Question 3 : Given an array of integers. Find the Inversion Count in the array. (HARD)
Inversion Count: For an array, inversion count indicates how far (or close) the array is
from being sorted. If the array is already sorted then the inversion count is 0. If an array 
is sorted in the reverse order then the inversion count is the maximum.

Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Sample Input 1 : N = 5, arr[ ] = {2, 4, 1, 3, 5}
Sample Output 1 : 3, because it has 3 inversions - (2, 1), (4, 1), (4, 3).

Sample Input 2 : N = 5, arr[ ] = {2, 3, 4, 5, 6}
Sample Output 2 : 0, because the array is already sorted

Sample Input 3 : N = 3, arr[] = {5, 5, 5}
Sample Output 3 : 0, because all the elements of the array are the same & already in a
sorted manner.

(Hint : A sorting algorithm will be used to solve this question.)

Note - This question is important. Even if you are not able to come up with the approach,
please understand the solution
*/

#include<iostream>
#include<vector>
using namespace std;

long long mergeAndCount(int arr[], int si, int mid, int ei) {
    vector<int> temp;

    int i = si;
    int j = mid + 1;

    long long count = 0;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (mid - i + 1);
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

    return count;
}

long long inversionRec(int arr[], int si, int ei) {
    if (si >= ei) {
        return 0;
    }

    int mid = si + (ei - si) / 2;
    long long count = 0;

    count += inversionRec(arr, si, mid);
    count += inversionRec(arr, mid + 1, ei);
    count += mergeAndCount(arr, si, mid, ei);

    return count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;

    cout << inversionRec(arr, 0, n - 1) << endl;
    return 0;
}