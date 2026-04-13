/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary 
(i.e., wrap-around is not allowed).

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// RECURSION (Brute Force)

int dfsRec(vector<vector<int>>& matrix, int i, int j, int n, int m) {

    int maxLen = 1; // at least the current cell

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
            matrix[ni][nj] > matrix[i][j]) {

            maxLen = max(maxLen, 1 + dfsRec(matrix, ni, nj, n, m));
        }
    }

    return maxLen;
}

int longestIncreasingPathRec(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfsRec(matrix, i, j, n, m));
        }
    }

    return ans;
}


// MEMOIZATION (DP)

int dfsMemo(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<vector<int>>& dp) {

    if (dp[i][j] != -1) return dp[i][j];

    int maxLen = 1;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
            matrix[ni][nj] > matrix[i][j]) {

            maxLen = max(maxLen, 1 + dfsMemo(matrix, ni, nj, n, m, dp));
        }
    }

    return dp[i][j] = maxLen;
}

int longestIncreasingPathMemo(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfsMemo(matrix, i, j, n, m, dp));
        }
    }

    return ans;
}


// TABULATION (Sorting-based DP)

int longestIncreasingPathTab(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<pair<int, pair<int,int>>> cells;

    // Store (value, (i,j))
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cells.push_back({matrix[i][j], {i, j}});
        }
    }

    // Sort by value
    sort(cells.begin(), cells.end());

    vector<vector<int>> dp(n, vector<int>(m, 1));

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (auto &cell : cells) {
        int i = cell.second.first;
        int j = cell.second.second;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                matrix[ni][nj] < matrix[i][j]) {

                dp[i][j] = max(dp[i][j], dp[ni][nj] + 1);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}



int main() {

    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << "Recursion Result: " << longestIncreasingPathRec(matrix) << endl;

    cout << "Memoization Result: " << longestIncreasingPathMemo(matrix) << endl;

    cout << "Tabulation Result: " << longestIncreasingPathTab(matrix) << endl;

    return 0;
}