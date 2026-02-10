#include<iostream>
using namespace std;

int countSetBits(int num) {
    int count = 0;
    
    while (num > 0) {
        int lastBit = num & 1; // Get the last bit
        count += lastBit; // Increment count if the last bit is 1
        num = num >> 1; // Right shift the bits to process the next bit
    }
    cout << count << endl;
    return count;
}

int main() {
    countSetBits(10);
    countSetBits(7);
    return 0;
}