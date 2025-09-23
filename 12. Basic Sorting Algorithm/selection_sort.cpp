#include<iostream>
using namespace std;

void print(int *arr, int n){

    for(int i=0; i<n; i++){

        cout << arr[i] << " ";
    }
    cout << endl;

}

void selectionSort(int arr[], int n){

    for(int i=0; i<n; i++){

        int minIDX = i;

        for(int j=i+1; j<n; j++){

            if (arr[j] < arr[minIDX]){

                minIDX = j;
            }
        }
        swap(arr[i], arr[minIDX]);

    }
    print(arr, n);
}

int main(){

    int arr[] = {5, 4, 1, 3, 2};
    selectionSort(arr, 5);

    return 0;
}