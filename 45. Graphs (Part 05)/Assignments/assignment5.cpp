/*
Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check 
whether these edges make up a valid tree.

Example 1:
Input: n = 5 , edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
Output: true

Example 2:
Input: n = 5 , edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
Output: false

Note: You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and 
thus will not appear together in edges.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<int> par;
    vector<int> rank;
public:
    int find(int x) {
        if (par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionSet(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() != n-1) {
            return false;
        }

        par.resize(n);
        rank.resize(n, 0);

        for (int i=0; i<n; i++) {
            par[i] = i;
        }

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int parU = find(u);
            int parV = find(v);

            if (parU == parV) {
                return false;
            }

            unionSet(u, v);
        }

        return true;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};

    Solution s;

    cout << s.validTree(n, edges1) << endl; //1
    cout << s.validTree(n, edges2) << endl; //0

}