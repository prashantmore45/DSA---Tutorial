// Kadane's Algorithm (Dynamic Programming):

#include <iostream>
using namespace std;

void maxSubarraySum3(int *arr, int n){

    int maxSum = INT32_MIN;
    int currSum = 0;

    for(int i=1; i<n; i++){
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if (maxSum < 0){

            currSum = 0;

        }
    }
    cout << "Maximun sum of subarray = " << maxSum << endl;
}
int main(){
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    maxSubarraySum3(arr, n);
    return 0;
}