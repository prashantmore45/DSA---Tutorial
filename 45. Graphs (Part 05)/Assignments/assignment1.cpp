/*
Question 1 : Redundant Connection
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and 
bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, 
return the answer that occurs last in the input.
*/

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
private:
    int n;
    vector<int> par;
    vector<int> rank;

public:
    DisjointSet(int n) {
        this->n = n;

        for (int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]); // path compression
    }

    // return true if union happens
    // return false if already in same set (cycle)
    bool unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB) {
            return false; // cycle detected
        }

        if (rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if (rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }

        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    DisjointSet ds(n + 1); // because nodes are 1-based

    vector<int> ans;

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        // if union fails → cycle edge
        if (!ds.unionByRank(u, v)) {
            ans = edge; // store last occurring answer
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};

    vector<int> res = findRedundantConnection(edges);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}