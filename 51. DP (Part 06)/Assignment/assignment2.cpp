/*
Question 2 : Maximum profit after buying and selling stocks with transaction fees
You are given an array of prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a 
transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee 
for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
*/

#include<iostream>
#include<vector>
using namespace std;

//recursion

int maxProfit(int i, int buy, vector<int>& prices, int fee) {
    // base case
    if (i == prices.size()) return 0;

    if (buy) {
        return max(
            -prices[i] + maxProfit(i+1, 0, prices, fee), // buy
            maxProfit(i+1, 1, prices, fee)              // skip
        );
    } else {
        return max(
            prices[i] - fee + maxProfit(i+1, 1, prices, fee), // sell
            maxProfit(i+1, 0, prices, fee)                   // skip
        );
    }
}

//memoization DP

int maxProfitMem(int i, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
    if (i == prices.size()) return 0;

    if (dp[i][buy] != -1) return dp[i][buy];

    if (buy) {
        return dp[i][buy] = max(
            -prices[i] + maxProfitMem(i+1, 0, prices, fee, dp), // buy
            maxProfitMem(i+1, 1, prices, fee, dp)              // skip
        );
    } else {
        return dp[i][buy] = max(
            prices[i] - fee + maxProfitMem(i+1, 1, prices, fee, dp), // sell
            maxProfitMem(i+1, 0, prices, fee, dp)                   // skip
        );
    }
}

//tabulation DP

int maxProfitTab(vector<int>& prices, int fee) {
    int n = prices.size();

    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    // base case already handled (dp[n][0] = dp[n][1] = 0)

    for (int i = n-1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {

            if (buy) {
                dp[i][buy] = max(
                    -prices[i] + dp[i+1][0], // buy
                    dp[i+1][1]              // skip
                );
            } else {
                dp[i][buy] = max(
                    prices[i] - fee + dp[i+1][1], // sell
                    dp[i+1][0]                   // skip
                );
            }

        }
    }

    return dp[0][1];
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    
    cout << maxProfit(0, 1, prices, fee) << endl; //8

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << maxProfitMem(0, 1, prices, fee, dp) << endl; //8

    cout << maxProfitTab(prices, 2) << endl; //8

    return 0;
}