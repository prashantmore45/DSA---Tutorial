//ptr + 1 or ptr + i

#include<iostream>
using namespace std;

int printArr(int *ptr, int n){
    for(int i=0; i<n; i++){
        cout << *ptr << " ";
        ptr = ptr + 1;  //also can be used as cout << (ptr + i) << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    printArr(arr, n);

    return 0;
}