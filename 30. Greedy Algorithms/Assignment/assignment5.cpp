/*
Question 5 : Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is 
minimized. Return the minimized largest sum of the split. (A subarray is a contiguous part of the array.) 

Example : Input: nums = [7,2,5,10,8], k = 2 Output: 18

Explanation: There are four ways to split nums into two subarrays.The best way is to split it into [7,2,5] and [10,8], 
where the largest sum among the two subarrays is only 18.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int splitArray(vector<int>& nums, int k) {
    long long low = 0, high = 0;

    // Define search space
    for (int num : nums) {
        low = max(low, (long long)num);
        high += num;
    }

    long long ans = high;

    // Binary Search
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        int count = 1;
        long long sum = 0;

        // Count subarrays needed
        for (int num : nums) {
            if (sum + num > mid) {
                count++;
                sum = num;
            } else {
                sum += num;
            }
        }

        // Adjust search space
        if (count <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << splitArray(nums, k) << endl;
    return 0;
}