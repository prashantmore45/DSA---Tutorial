#include<iostream>
#include<vector>
using namespace std;


void dfs(int row, int col, int n, int m, vector<vector<int>> &image, vector<vector<bool>> &vis, int newColor, int oldColor) {
    vis[row][col] = true;
    image[row][col] = newColor;

    //UP
    if (row-1 >= 0 && !vis[row-1][col] && image[row-1][col] == oldColor) {
        dfs(row-1, col, n, m, image, vis, newColor, oldColor);
    }

    //DOWN
    if (row+1 < n && !vis[row+1][col] && image[row+1][col] == oldColor) {
        dfs(row+1, col, n, m, image, vis, newColor, oldColor);
    }

    //LEFT
    if (col-1 >= 0 && !vis[row][col-1] && image[row][col-1] == oldColor) {
        dfs(row, col-1, n, m, image, vis, newColor, oldColor);
    }

    //RIGHT
    if (col+1 < m && !vis[row][col+1] && image[row][col+1] == oldColor) {
        dfs(row, col+1, n, m, image, vis, newColor, oldColor);
    }
}

vector<vector<int>> floodFill(int sr, int sc, vector<vector<int>> image, int newColor) {
    int n = image.size();
    int m = image[0].size();

    vector<vector<bool>> vis(n, vector<bool> (m, false));
    dfs(sr, sc, n, m, image, vis, newColor, image[sr][sc]);
    return image;
}

void printfloodFill(vector<vector<int>> result) {
    int n = result.size();
    int m = result[0].size();
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    vector<vector<int>> result = floodFill(1, 1, image, 2);

    printfloodFill(result);

    return 0;
}