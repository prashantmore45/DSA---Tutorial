#include<iostream>
#include<vector>
using namespace std;

//count BSTs using catalan tabulation DP 
int countBSTs(int n) {
    vector<int> dp(n+1, 0);

    dp[0] = dp[1] = 1;

    for (int i=2; i<=n; i++) {
        for (int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main() {
    int n1 = 2; //node : 10, 20 ; ans = 2
    int n2 = 3; //node : 10, 20, 30 ; ans = 5
    int n3 = 4; //node : 10, 20, 30, 40 ; ans = 14

    cout << countBSTs(n1) << endl; //2
    cout << countBSTs(n2) << endl; //5
    cout << countBSTs(n3) << endl; //14

    return 0;
}