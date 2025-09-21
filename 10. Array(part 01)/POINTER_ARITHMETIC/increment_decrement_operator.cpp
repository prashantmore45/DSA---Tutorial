//Increment and Decrement Operators:
//ptr++ or ptr--
//++ptr or --ptr

#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int *ptr = &a;
    cout << ptr << "\n";
    ptr++;
    cout << ptr << "\n";
    ptr--;
    cout << ptr << "\n";
    return 0;
}