/* Question 2 : There is an integer array nums sorted in ascending order (with distinct 
values). 

Prior to being passed to your function, nums is possibly rotated at an unknown pivot 
index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., 
nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] 
might be rotated at pivot index 3 and become [4,5,6,7,0,1,2]. 

Given the array nums after the possible rotation and an integer target, return the 
index of target if it is in nums, or -1 if it is not in nums. 

You must write an algorithm with O(log n) runtime complexity. [link] 

Examples : 
Input: nums = [4,5,6,7,0,1,2], target = 0 Output: 
4 

Input: nums = [4,5,6,7,0,1,2], target = 3 Output: 
1  */


#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) { 
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // To avoid overflow
       
        if (nums[mid] == target) { 
            return mid;  // Target found
        }

        // Check if the left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;  // Search in the left half
            } else {
                low = mid + 1;   // Search in the right half
            }
        }
        // Right half is sorted
        else {  
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;  // Search in the right half
            } else {
                high = mid - 1;  // Search in the left half
            }
        }
    }
    return -1;  // Target not found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};  // Rotated sorted array
    int target = 0;

    int result = search(nums, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
