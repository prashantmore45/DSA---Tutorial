#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int mcmTab(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        dp[i][i] = 0; // i == j => len = 1 
    }

    for (int len=2; len<n; len++) {
        for (int i=1; i<=n-len; i++) {
            int j = i+len-1;
            dp[i][j] = INT_MAX;

            for (int k=i; k<j; k++) {
                int cost1 = dp[i][k]; //(i, k)
                int cost2 = dp[k+1][j]; //(k+1, j)

                int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);

                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[1][n-1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3}; //n -> n-1 matrices(1 to n-1)
    
    cout << mcmTab(arr) << endl; //30

    return 0;
}