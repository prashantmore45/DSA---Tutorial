//Counting Sorting in Descending Order:

#include<iostream>
using namespace std;

void print(int *arr, int n){

    for(int i=0; i<n; i++){

        cout << arr[i] << ' ';
    }
    cout << endl;
}

void countSort(int arr[], int n){

    int freq[100000] = {0};
    int minVal = INT32_MAX, maxVal = INT32_MIN;

    for(int i=0; i<n; i++){

        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);


    }
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]] ++;
    }

    for (int i = maxVal, j=0; i >= minVal; i--)
    {
        while(freq[i] > 0){

            arr[j++] = i;
            freq[i] --;

        }
    }
    print(arr, n);
    
    
}
 
int main(){

    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    countSort(arr, 10);
    return 0;
}