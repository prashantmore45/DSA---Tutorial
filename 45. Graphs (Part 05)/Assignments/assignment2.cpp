/*
Question 2 : Rotting Oranges
You are given an m x n grid where each cell can have one of three values:
● 0 representing an empty cell,
● 1 representing a fresh orange, or
● 2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. 
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>> q;
    int fresh = 0;

    // push all rotten + count fresh
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
            else if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // directions: up, down, left, right
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    int time = 0;

    // Step 2: BFS
    while(!q.empty() && fresh > 0) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            for(auto d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;

                // valid + fresh orange
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // make rotten
                    q.push({nr, nc});
                    fresh--;
                }
            }
        }

        time++; // one minute passed
    }

    // if fresh left → impossible
    return (fresh == 0) ? time : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << orangesRotting(grid);
}