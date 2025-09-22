/* Question 1 : Given an integer array nums, return true if any value appears at least 
twice in the array, and return false if every element is distinct. [link] 

Examples : 
Input: nums = [1,2,3,4] 
Output: false 

Input: nums = [1,1,1,3,3,4,3,2,4,2] 
Output: true */

/*
#include<iostream>
using namespace std;

bool check(int *nums, int n){
    for(int start=0; start<n; start++){
        for(int end = start+1; end < n; end++){
            if (nums[start] == nums[end]){
                return true;
            }
            
        }
    }
    return false;
}

int main(){

    //int nums[] = {1, 2, 3, 4};
    int nums[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int n = sizeof(nums) / sizeof(int);
    cout << check(nums, n) << endl;
    return 0;
} */

#include <iostream>
#include <vector>
#include <algorithm>  // For sorting
using namespace std;

bool containsDuplicate(vector<int>& nums) { 
    sort(nums.begin(), nums.end());  // Sort the vector

    for (int i = 1; i < nums.size(); i++) { 
        if (nums[i - 1] == nums[i]) { 
            return true;  // Duplicate found
        } 
    }
    return false;  // No duplicates
}

int main() {
    vector<int> nums = {1, 2, 3, 4};  

    if (containsDuplicate(nums)) {
        cout << "Duplicate found!" << endl;
    } else {
        cout << "No duplicates." << endl;
    }

    return 0;
}
