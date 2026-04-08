//A person can climb 1, 2 or 3 stairs at a time

#include<iostream>
#include<vector>
using namespace std;

int countWaysRec(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    return countWaysRec(n-1) + countWaysRec(n-2) + countWaysRec(n-3);
}


int main() {
    int n = 4;

    cout << countWaysRec(n) << endl; //7

    
    return 0;
}