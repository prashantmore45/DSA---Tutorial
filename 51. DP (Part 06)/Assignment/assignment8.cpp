/*
Question 8 : Mountain Array(Longest Bitonic Subsequence) 
● arr.length >= 3 
Given an integer array nums, return true if you can partition the array into two subsets such 
that the sum of the elements in both subsets is equal or false otherwise. [Go to Qs] 
You may recall that an array arr is a mountain array if and only if: 
● There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that: 
○ arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
○ arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 
Given an integer array nums, return the minimum number of elements to remove to make 
nums a mountain array.
*/

#include <iostream>
#include <vector>
using namespace std;

// LIS ending at i
int LIS(int i, vector<int>& nums) {
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
            ans = max(ans, 1 + LIS(j, nums));
        }
    }
    return ans;
}

// LDS starting at i
int LDS(int i, vector<int>& nums, int n) {
    int ans = 1;
    for (int j = i + 1; j < n; j++) {
        if (nums[j] < nums[i]) {
            ans = max(ans, 1 + LDS(j, nums, n));
        }
    }
    return ans;
}

int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    int maxBitonic = 0;

    for (int i = 0; i < n; i++) {
        int lis = LIS(i, nums);
        int lds = LDS(i, nums, n);

        if (lis > 1 && lds > 1) {
            maxBitonic = max(maxBitonic, lis + lds - 1);
        }
    }

    return n - maxBitonic;
}

int main() {
    vector<int> nums = {2,1,1,5,6,2,3,1};
    cout << minimumMountainRemovals(nums);
}