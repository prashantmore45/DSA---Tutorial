#include<iostream>
#include<vector>
using namespace std;

int catalanTab(int n) {
    vector<int> dp(n+1, 0); //storage(n+1, 0) + meaning(dp[i] = Ci)

    dp[0] = dp[1] = 1; //initialization

    for (int i=2; i<=n; i++) {  //ith catalan
        for (int j=0; j<=i-1; j++) {  //0 to i-1
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main() {
    int n = 5;

    cout << catalanTab(n) << endl; //42
    return 0;
}