/*
Question 5 : House Thief 
You are a professional robber planning to rob houses along a street. Each house has a 
certain amount of money stashed, the only constraint stopping you from robbing each of 
them is that adjacent houses have security systems connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night. 
Given an integer array nums representing the amount of money of each house, return the 
maximum amount of money you can rob tonight without alerting the police. 
*/

#include<iostream>
#include<vector>
using namespace std;


// RECURSION 
int robRec(int i, vector<int>& nums) {
    if (i >= nums.size()) return 0;

    int rob = nums[i] + robRec(i + 2, nums);
    int skip = robRec(i + 1, nums);

    return max(rob, skip);
}


// MEMOIZATION
int robMem(int i, vector<int>& nums, vector<int>& dp) {
    if (i >= nums.size()) return 0;

    if (dp[i] != -1) {
        return dp[i];
    }

    int rob = nums[i] + robMem(i + 2, nums, dp);
    int skip = robMem(i + 1, nums, dp);

    return dp[i] = max(rob, skip);
}


// TABULATION
int robTab(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}


int main() {
    vector<int> nums = {1, 2, 3, 1};

    // Recursion
    cout << robRec(0, nums) << endl;   // 4

    // Memoization
    vector<int> dp(nums.size(), -1);
    cout << robMem(0, nums, dp) << endl; // 4

    // Tabulation
    cout << robTab(nums) << endl; // 4

    return 0;
}