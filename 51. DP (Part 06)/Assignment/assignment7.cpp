/*
Question 7 : Equal Subset Sum Difference 

Given an integer array nums, return true if you can partition the array into two subsets such 
that the sum of the elements in both subsets is equal or false otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// RECURSION

bool solveRec(vector<int>& nums, int i, int target) {
    if (target == 0) return true;
    if (i >= nums.size()) return false;

    // Take
    if (nums[i] <= target) {
        if (solveRec(nums, i + 1, target - nums[i]))
            return true;
    }

    // Skip
    return solveRec(nums, i + 1, target);
}

bool canPartitionRec(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 != 0) return false;

    return solveRec(nums, 0, sum / 2);
}

// MEMOIZATION (Top-Down DP)

bool solveMemo(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (i >= nums.size()) return false;

    if (dp[i][target] != -1)
        return dp[i][target];

    bool take = false;
    if (nums[i] <= target)
        take = solveMemo(nums, i + 1, target - nums[i], dp);

    bool skip = solveMemo(nums, i + 1, target, dp);

    return dp[i][target] = take || skip;
}

bool canPartitionMemo(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 != 0) return false;

    int target = sum / 2;
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return solveMemo(nums, 0, target, dp);
}

// TABULATION (Bottom-Up DP)

bool canPartitionTab(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 != 0) return false;

    int target = sum / 2;
    int n = nums.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int t = 1; t <= target; t++) {
            if (nums[i - 1] <= t) {
                dp[i][t] = dp[i - 1][t - nums[i - 1]] || dp[i - 1][t];
            } else {
                dp[i][t] = dp[i - 1][t];
            }
        }
    }

    return dp[n][target];
}


int main() {
    vector<int> nums = {1, 5, 11, 5};

    cout << "Recursion: " << (canPartitionRec(nums) ? "True" : "False") << endl;
    cout << "Memoization: " << (canPartitionMemo(nums) ? "True" : "False") << endl;
    cout << "Tabulation: " << (canPartitionTab(nums) ? "True" : "False") << endl;

    return 0;
}
