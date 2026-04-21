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


int main() {
    vector<int> nums = {1, 5, 11, 5};

    cout << "Recursion: " << (canPartitionRec(nums) ? "True" : "False") << endl;

    return 0;
}
