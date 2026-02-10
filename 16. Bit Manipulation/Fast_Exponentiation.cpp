#include<iostream>
using namespace std;

void fastExponentiation(int x, int n) {
    int ans = 1;

    while (n > 0)
    {
        int lastBit = n & 1; // Get the last bit
        if (lastBit) {
            ans = ans * x;
        }

        x = x * x;
        n = n >> 1;
    }
    cout << ans << endl;
}

int main() {
    fastExponentiation(3, 5);
    fastExponentiation(3, 4);
    return 0;
}