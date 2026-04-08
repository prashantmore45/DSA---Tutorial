#include<iostream>
#include<vector>
using namespace std;

int countWays(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return countWays(n-1) + countWays(n-2);
}


int countWaysMem(int n, vector<int> &dp) {
    if (n == 0 || n == 1) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = countWaysMem(n-1, dp) + countWaysMem(n-2, dp);
    
    return dp[n];
}


int main() {
    int n = 4;
    cout << countWays(n) << endl; // 5

    vector<int> dp(n+1, -1);
    
    cout << countWaysMem(n, dp) << endl;  //5
    
    return 0;
}