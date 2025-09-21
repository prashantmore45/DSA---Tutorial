//arrays are passed by refernce :

#include<iostream>
using namespace std;

void printArr(int nums[], int n){
    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {7, 8, 3, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    printArr(arr, n);
    return 0;
}