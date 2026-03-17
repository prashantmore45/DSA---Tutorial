/*
Question 4 : Given n non-negative integers representing an elevation map 
where thewidth of each bar is 1, compute how much water it can trap after
raining.

Examples :
Input: height = [7, 0, 4, 2, 5, 0, 6, 4, 0, 5]
Output: 25
Explanation: The above elevation map (black section) is represented by the array [7, 0, 4, 2, 5, 0, 6, 4, 0, 5]. 
In this case, 25 units of rain water (blue section) are being trapped.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int trappedWater(vector<int>& height) {

    stack<int> s;
    int water = 0;

    for(int i = 0; i < height.size(); i++) {

        while(!s.empty() && height[i] > height[s.top()]) {

            int mid = s.top();
            s.pop();

            if(s.empty()) break;

            int left = s.top();

            int width = i - left - 1;

            int h = min(height[left], height[i]) - height[mid];

            water += width * h;
        }

        s.push(i);
    }

    return water;
}

int main() {

    vector<int> height = {7,0,4,2,5,0,6,4,0,5};

    cout << trappedWater(height) << endl;

    return 0;
}