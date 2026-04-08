#include<iostream>
using namespace std;

int countWays(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return countWays(n-1) + countWays(n-2);
}


int main() {
    int n = 4;
    cout << countWays(n) << endl; // 5
    
    return 0;
}