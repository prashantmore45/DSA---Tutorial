#include<iostream>
using namespace std;

int setIthBit(int num, int i) {
    int bitMask = 1 << i;
    return (num | bitMask);
}

int main() {
    cout << setIthBit(6, 3) << endl; // Output: 14
    cout << setIthBit(4, 0) << endl; // Output: 5
    return 0;
}