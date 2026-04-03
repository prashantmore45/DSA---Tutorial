#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> * l;
    bool isDir;
public:
    Graph(int V, bool isDir = true) {
        this->V = V;
        l = new list<int> [V];
        this->isDir = isDir;
    }

    void addEdge(int u, int v) { //u---->v
        l[u].push_back(v);
        if (!isDir) {
            l[v].push_back(u);
        }
    }

    bool dirCycleHelper(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors) {
            if (!vis[v]) {
                if (dirCycleHelper(v, vis, recPath)) {
                    return true;
                }
            } else {
                if (recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    bool isDirCycle() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                if (dirCycleHelper(i, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph graph(4, true);

    graph.addEdge(0, 2);
    graph.addEdge(1, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout << graph.isDirCycle() << endl; //1
    return 0;
}