#include <iostream>
using namespace std;

int clearIthBit(int num, int i) {
    int bitMask = ~(1 << i);
    return (num & bitMask);
}

int main() {

    cout << clearIthBit(6, 1) << endl; // Output: 4
    cout << clearIthBit(15, 3) << endl; // Output: 7

    return 0;
}