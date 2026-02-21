/*
Question 1 : Rat in a Maze

You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the 
maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a 
square matrix of order N * N where the cells with value 0 represent the maze’s blocked 
locations while value 1 is the open/available path that the rat can take to reach its destination. 
The rat's destination is at (N - 1, N - 1).

Your task is to find all the possible paths that the rat can take to reach from source to 
destination in the maze.

The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down)
i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).

(This problem is similar to Grid ways.)

Sample Input : int maze[ ][ ] = {{ 1, 0, 0, 0 },
                                 { 1, 1, 0, 1 },
                                 { 1, 1, 0, 0 },
                                 { 0, 1, 1, 1 }};
Sample Output : DDRDRR
                DRDDRR

*/

#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

int ratMaze(int r, int c, int maze[][4], int n, string ans, bool visited[][4]) {

    // Base case: destination reached
    if (r == n - 1 && c == n - 1) {
        cout << ans << endl;
        return 1;
    }

    // Out of bounds or blocked or already visited
    if (r < 0 || c < 0 || r >= n || c >= n ||
        maze[r][c] == 0 || visited[r][c] == true) {
        return 0;
    }

    // Mark current cell as visited
    visited[r][c] = true;

    int count = 0;

    // Right
    count += ratMaze(r, c + 1, maze, n, ans + 'R', visited);

    // Down
    count += ratMaze(r + 1, c, maze, n, ans + 'D', visited);

    // Left
    count += ratMaze(r, c - 1, maze, n, ans + 'L', visited);

    // Up
    count += ratMaze(r - 1, c, maze, n, ans + 'U', visited);

    // Backtrack
    visited[r][c] = false;

    return count;
}

int main() {
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    bool visited[4][4] = {false};
    string ans = "";

    cout << ratMaze(0, 0, maze, 4, ans, visited) << endl;

    return 0;
}
