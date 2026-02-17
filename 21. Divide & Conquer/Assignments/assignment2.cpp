/*
Question 2 : Given an array nums of size n, return the majority element. (MEDIUM)
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume
that the majority element always exists in the array.

Sample Input 1 : nums = [3,2,3]
Sample Output 1 : 3

Sample Input 2 : nums = [2,2,1,1,1,2,2]
Sample Output 2 : 2

Constraints (extra Conditions):
● n == nums.length
● 1 <= n <= 5 * 104
● -109 <= nums[i] <= 109
*/

#include<iostream>
using namespace std;

int countInRange(int nums[], int si, int ei, int target) {
    int count = 0;
    for (int i = si; i <= ei; i++) {
        if (nums[i] == target) {
            count++;
        }
    }
    return count;
}

int majorityRec(int nums[], int si, int ei) {
    // Base Case: only one element
    if (si == ei) {
        return nums[si];
    }

    int mid = si + (ei - si) / 2;

    int leftMajor = majorityRec(nums, si, mid);
    int rightMajor = majorityRec(nums, mid + 1, ei);

    // If both halves agree
    if (leftMajor == rightMajor) {
        return leftMajor;
    }

    // Otherwise count both
    int leftCount = countInRange(nums, si, ei, leftMajor);
    int rightCount = countInRange(nums, si, ei, rightMajor);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int majority(int nums[], int n) {
    return majorityRec(nums, 0, n - 1);
}

int main() {
    int nums1[] = {3, 2, 3};
    cout << majority(nums1, 3) << endl;   // 3

    int nums2[] = {2,2,1,1,1,2,2};
    cout << majority(nums2, 7) << endl;   // 2

    return 0;
}
