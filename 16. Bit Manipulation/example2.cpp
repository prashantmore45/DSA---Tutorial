/* Q.WAF to clear last i bits of a number.
num = 15 (1111 in binary), i = 2
Output: 12 (1100 in binary) 
*/

#include<iostream>
using namespace std;


void clearIBits(int num, int i) {
    int bitMask = (~0) << i; // Create a bitmask with last i bits as 0 and rest as 1
    num = num & bitMask; // Clear the last i bits of num
    cout << "Number after clearing last " << i << " bits: " << num << endl;
}

int main() {
    clearIBits(15, 2); // Output: Number after clearing last 2 bits: 12
    return 0;
}
