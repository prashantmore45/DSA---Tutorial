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

int countWaysTab(int n) {

    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;

    vector<int> dp(n+1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


int main() {
    int n = 4;
    cout << countWays(n) << endl; // 5

    vector<int> dp(n+1, -1);
    
    cout << countWaysMem(n, dp) << endl;  //5

    cout << countWaysTab(n) << endl; //5
    
    return 0;
}