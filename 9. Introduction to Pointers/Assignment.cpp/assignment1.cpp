// What will be the output of the following code :

#include<iostream>
using namespace std;

int main(){

    int x;
    int *ptr;
    x = 7;
    ptr = &x;

    cout << *ptr << "\n";
    return 0;
}