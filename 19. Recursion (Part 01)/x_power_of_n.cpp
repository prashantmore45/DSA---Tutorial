#include<iostream>
using namespace std;

int power(int x, int n) {

    if (n == 0) {
        return 1;
    }

    int halfpow = power(x, n/2);
    int halfPowSquare = halfpow * halfpow;

    if (n % 2 != 0 ) {
        //odd
        return x * halfPowSquare;
    }

    return halfPowSquare;
}

int main() {
    cout << power(2, 10) << endl;
    return 0;
}