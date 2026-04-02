#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> * l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {  //edge : u----v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print() {
        for (int u=0; u<V; u++) {
            list<int> neighbors = l[u];
            cout << u << " : ";
            for (int v : neighbors) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool undireCycleHelper(int src, int par, vector<bool> &vis) {
        vis[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors) {
            if (!vis[v]) {
                if (undireCycleHelper(v, src, vis)) {
                    return true;
                }
            } else {
                if (v != par) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycleUndire() {
        vector<bool> vis(V, false);
        return undireCycleHelper(0, -1, vis);
    }
}; 


int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);

    graph.addEdge(1, 2);

    graph.addEdge(3, 4);
  
    cout << graph.isCycleUndire() << endl; //1
    return 0;
}