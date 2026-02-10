#include<iostream>
using namespace std;

void oddOrEven(int num) {
    if (!(num & 1)) {  // Check the least significant bit
        cout << num << " is even." << endl;
    } else {
        cout << num << " is odd." << endl;
    }
}

int main() {
    oddOrEven(5);
    oddOrEven(8);
    return 0;
}