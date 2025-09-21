#include<iostream>
using namespace std;

int main(){
    int arr[5] = {7, 8, 9, 5, 2};
    int n = sizeof(arr) / sizeof(int);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}