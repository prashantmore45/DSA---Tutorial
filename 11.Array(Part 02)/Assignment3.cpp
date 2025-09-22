/* Question 3 : Given an integer array nums, find a subarray that has the largest 
product, and return the product. The test cases are generated so that the answer will 
fit in a 32-bit integer. [link] 

Note - This Qs might feel difficult as a beginner because it uses DP approach. 

Examples : 
Input: nums = [2,3,-2,4] 
Output: 6 

Explanation: [2,3] has the largest product 6. 
Input: intervals =nums = [-2,0,-1] 
Output: 0 

Explanation: The result cannot be 2, because [-2,-1] is not a subarray.  */

#include <iostream>
#include <vector>
#include <algorithm>  // For max() and min()
using namespace std;

int maxProduct(vector<int>& nums) { 
    int maxTillNow = nums[0]; 
    int minTillNow = nums[0]; 
    int ans = maxTillNow; 
     
    for (int i = 1; i < nums.size(); i++) {
        int curr = nums[i];

        int tempMaxTillNow = max(curr, max(maxTillNow * curr, minTillNow * curr));
        minTillNow = min(curr, min(maxTillNow * curr, minTillNow * curr));
        maxTillNow = tempMaxTillNow;

        ans = max(maxTillNow, ans); 
    }
    return ans; 
} 

int main() {
    vector<int> nums = {2, 3, -2, 4};  // Example array

    int result = maxProduct(nums);
    cout << "Maximum Product Subarray: " << result << endl;

    return 0;
}
