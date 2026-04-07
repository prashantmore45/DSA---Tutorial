/*
Question 3 : Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally 
(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in the grid. If there is no island, return 0.
*/

#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();

    // base case
    if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
        return 0;
    }

    // mark visited
    grid[i][j] = 0;

    int area = 1;

    // explore 4 directions
    area += dfs(grid, i+1, j);
    area += dfs(grid, i-1, j);
    area += dfs(grid, i, j+1);
    area += dfs(grid, i, j-1);

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int maxArea = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                int area = dfs(grid, i, j);
                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0},
        {1,1,1,0,1},
        {0,1,0,0,1},
        {0,0,0,1,1}
    };

    cout << maxAreaOfIsland(grid);
}