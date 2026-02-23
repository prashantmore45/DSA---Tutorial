/*
Question 3 : Knight’s Tour

Given a N*N board with the Knight placed on the first block of an empty board. Moving 
according to the rules of chess, knights must visit each square exactly once. Print the order
of each cell in which they are visited.

Sample Input 1 : N = 8
Sample Output 1 :
0 59 38 33 30 17 8 63
37 34 31 60 9 62 29 16
58 1 36 39 32 27 18 7
35 48 41 26 61 10 15 28
42 57 2 49 40 23 6 19
47 50 45 54 25 20 11 14
56 43 52 3 22 13 24 5
51 46 55 44 53 4 21 12

(Hint : Similar to N Queens)
*/


#include <iostream>
using namespace std;

// Check if next move is valid
bool isSafe(int x, int y, int sol[][8], int N) {
    return (x >= 0 && x < N &&
            y >= 0 && y < N &&
            sol[x][y] == -1);
}

// Print solution
void printSolution(int sol[][8], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

// Backtracking function
bool solveKTUtil(int x, int y, int movei,
                 int sol[][8],
                 int xMove[], int yMove[],
                 int N) {

    // Base case
    if (movei == N * N)
        return true;

    // Try all 8 possible moves
    for (int k = 0; k < 8; k++) {

        int next_x = x + xMove[k];
        int next_y = y + yMove[k];

        if (isSafe(next_x, next_y, sol, N)) {

            sol[next_x][next_y] = movei;

            if (solveKTUtil(next_x, next_y,
                            movei + 1,
                            sol, xMove, yMove, N))
                return true;

            // Backtracking
            sol[next_x][next_y] = -1;
        }
    }

    return false;
}

bool solveKT(int N) {

    int sol[8][8];

    // Initialize board with -1
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = -1;

    // Knight moves
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

    // Starting position
    sol[0][0] = 0;

    if (!solveKTUtil(0, 0, 1,
                     sol, xMove, yMove, N)) {

        cout << "Solution does not exist\n";
        return false;
    }
    else {
        printSolution(sol, N);
    }

    return true;
}

int main() {
    int N = 8;
    solveKT(N);
    return 0;
}