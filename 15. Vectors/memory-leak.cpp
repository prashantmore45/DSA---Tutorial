#include<iostream>
using namespace std;

int* funcArr() {
    int *ptr = new int;
    *ptr = 1200;
    cout << "ptr points to: " << *ptr << endl;

    return ptr;
}

int main() {

    int *p = funcArr();
    cout << *p << endl;

    return 0;
}