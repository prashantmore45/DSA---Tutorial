#include<iostream>
using namespace std;

void UpdateIthBit(int num, int i, int val) {
    num = num & ~(1 << i); // Clear the ith bit
    num = num | (val << i); // Set the ith bit to val
    cout << "Updated number: " << num << endl;
}

int main() {
    UpdateIthBit(7, 2, 0); // Output: Updated number: 3
    UpdateIthBit(7, 3, 1); // Output: Updated number: 15
    return 0;
}