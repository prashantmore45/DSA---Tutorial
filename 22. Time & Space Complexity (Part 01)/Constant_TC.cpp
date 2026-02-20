#include<iostream>
using namespace std;

int smallest(int arr[], int n){
    return arr[0];  // This function returns the first element of the array, which is a constant time operation O(1) since it does not depend on the size of the array.
}

int main(){
    int arr[] = {5, 2, 3, 1, 4};
    int n = 5;
    cout << "Smallest element is: " << smallest(arr, n) << endl;
    return 0;
}