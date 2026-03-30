/*
Question 2 : Two Sum

Given an array of integers arr[] and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer 
in any order. 

Sample Input 1 : arr = [2, 7, 11, 15], target = 9
Sample Output 1 : [0, 1]

As arr[0] + arr[1] == 9, we return [0, 1].

Sample Input 2 : arr = [3,2,4], target = 6
Sample Output 2 : [1, 2]
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void twoSum(vector<int> arr, int target) {
    unordered_map<int, int> m;

    for (int i=0; i<arr.size(); i++) {
        int comp = target - arr[i];
        if (m.count(comp)) {
            cout << "ans = " << "[" << m[comp] << ", " << i << "]" << endl;
            break;
        }

        m[arr[i]] = i;
    }
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    twoSum(arr, target);
    return 0;
}