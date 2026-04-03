#include<iostream>
#include<vector>
#include<stack>
using namespace std;


bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &graph) {
    vis[src] = true;
    recPath[src] = true;

    for (int i=0; i<graph.size(); i++) {
        int u = graph[i][1]; //prereq
        int v = graph[i][0]; //course

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

void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &graph) {
    vis[src] = true;

    for (int i=0; i<graph.size(); i++) {
        int prereq = graph[i][1];
        int course = graph[i][0];

        if (prereq == src) {
            if (!vis[course]) {
                topoSort(course, vis, s, graph);
            }
        }
    }

    s.push(src);
}

vector<int> findOrder(int numCourse, vector<vector<int>> &prereqsites) {  // numCourse => V; prereqsites => graph 
    int V = numCourse; // [v, u] ; v <--- u
    vector<bool> vis(V, false);
    vector<bool> recPath(V, false);
    vector<int> ans;

    for (int i=0; i<V; i++) {
        if (!vis[i]) {
            if (isCycle(i, vis, recPath, prereqsites)) {
                return ans;
            }
        }
    }

    //topological sorting 
    vector<bool> vis2(V, false);
    stack<int> s;

    for (int i=0; i<V; i++) {
        if (!vis2[i]) {
            topoSort(i, vis2, s, prereqsites);
        }
    }

    //print topological order
    while (s.size() > 0) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main() {
    vector<vector<int>> prereqsites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourse = 4;
    
    vector<int> result = findOrder(numCourse, prereqsites);

    for (int course : result) {
        cout << course << " ";
    }
    cout << endl;
    
    return 0;
}