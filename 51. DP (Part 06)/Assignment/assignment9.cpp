/*
Question 9 : Box Stacking 
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). 
Choose a subset of cuboids and place them on each other. 
You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. 
You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.  
Return the maximum height of the stacked cuboids.

Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Recursion

int solveRec(int i, int prev, vector<vector<int>>& c) {
    if (i == c.size()) return 0;

    // skip
    int notTake = solveRec(i+1, prev, c);

    // take
    int take = 0;
    if (prev == -1 ||
        (c[i][0] >= c[prev][0] &&
         c[i][1] >= c[prev][1] &&
         c[i][2] >= c[prev][2])) {
        
        take = c[i][2] + solveRec(i+1, i, c);
    }

    return max(take, notTake);
}


int main() {
    vector<vector<int>> cuboids = {
        {50,45,20},
        {95,37,53},
        {45,23,12}
    };

    // preprocessing
    for (auto &c : cuboids) sort(c.begin(), c.end());
    sort(cuboids.begin(), cuboids.end());

    int n = cuboids.size();

    // Recursion
    cout << solveRec(0, -1, cuboids) << endl;

    return 0;
}