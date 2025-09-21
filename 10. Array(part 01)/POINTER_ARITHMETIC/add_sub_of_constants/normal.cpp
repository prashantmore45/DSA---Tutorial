//ptr + n or ptr - n
// eg. ptr + 3 or ptr - 3

#include<iostream>
using namespace std;

int main(){

    int a = 5;
    int *ptr = &a;

    cout << ptr << "\n";
    ptr = ptr + 3;
    cout << ptr << "\n";
    cout << ptr - 3 << endl;

    return 0;
}