//Slightly Optimized:

#include<iostream>
using namespace std;

void maxSubarraySum2(int *arr, int n){
    int maxSum = INT32_MIN;
    for (int start = 0; start < n; start++)
    {
        int currSum = 0;
        for (int end = start; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);

        }

        
    }
    cout << "maximum subarray sum = " << maxSum << endl;
    
}
int main(){

    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    maxSubarraySum2(arr, n);
    return 0;
    
}