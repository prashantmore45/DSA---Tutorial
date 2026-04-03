#include<iostream>
#include<vector>
using namespace std;


bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &graph) {
    vis[src] = true;
    recPath[src] = true;

    for (int i=0; i<graph.size(); i++) {
        int u = graph[i][0];
        int v = graph[i][1];

        if (u == src) {
            if (!vis[v]) {
                if (isCycle(v, vis, recPath, graph)) {
                    return true;
                }
            } else {
                if (recPath[v]) {
                    return true;
                }
            }
        }
    }
    recPath[src] = false;
    return false;
}

bool canFinish(int numCourse, vector<vector<int>> &prereqsites) {  // numCourse => V; prereqsites => graph 
    int V = numCourse; // [v, u] ; v <--- u
    vector<bool> vis(V, false);
    vector<bool> recPath(V, false);

    for (int i=0; i<V; i++) {
        if (!vis[i]) {
            if (isCycle(i, vis, recPath, prereqsites)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> prereqsites = {{1, 0}};
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourse = 2;

    cout << canFinish(numCourse, prereqsites) << endl; //1
    cout << canFinish(numCourse, prerequisites) << endl; //0
    return 0;
}