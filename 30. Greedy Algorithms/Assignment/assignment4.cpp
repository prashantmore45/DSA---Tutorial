/*
Question 4 : Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit 
by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example : Input: prices = [7,1,5,3,6,4] Output: 5

Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Note : This question was already covered in class lectures of previous chapters.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        // Create array to store max future prices
        vector<int> maxArr(n);
        maxArr[n - 1] = prices[n - 1];

        // Fill maxArr[] from right to left
        for (int i = n - 2; i >= 0; i--) {
            maxArr[i] = max(maxArr[i + 1], prices[i]);
        }

        // Calculate maximum profit
        for (int i = 0; i < n; i++) {
            int currProfit = maxArr[i] - prices[i];
            profit = max(profit, currProfit);
        }

        cout << "maximum profit = " << profit << endl;
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    s.maxProfit(prices);

    return 0;
}