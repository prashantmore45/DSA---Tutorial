#include<iostream>
#include<stack>
#include<vector>
#include <algorithm>
using namespace std;

void maxAreaHistogram(vector<int> height) {
    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    //next smaller left
    nsl[0] = -1;
    s.push(0);

    for (int i = 1; i < n; i++) {
        int curr = height[i];

        while (!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }

        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }

    //next smaller right;
    nsr[n-1] = n;
    s.push(n-1);

    for (int i = n-2; i >= 0; i--) {
        int curr = height[i];

        while (!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }

        s.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int h = height[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = h * width;

        maxArea = max(area, maxArea);
    }

    cout << "max area of histogram: " << maxArea << endl;
}

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};
    maxAreaHistogram(height);
    return 0;
}