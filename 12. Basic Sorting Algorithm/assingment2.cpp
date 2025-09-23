//selection sort in descending order:

#include<iostream>
using namespace std;

void print(int *arr, int n){

    for(int i=0; i<n; i++){

        cout << arr[i] << ' ';

    }
    cout << endl;
}

void seletionSort(int arr[], int n){

    for(int i=0; i<n; i++){

        int minIDX = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] > arr[minIDX]){

                minIDX = j;
            }
            
        }
        swap(arr[i], arr[minIDX]);
        
    }
    print(arr, n);
}

int main(){

    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    seletionSort(arr, 10);
    return 0;
}

