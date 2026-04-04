#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (!isDir) {
            l[v].push_back(u);
        }
    }

    void calIndegree(vector<int> &indegree) { 
        for (int u=0; u<V; u++) {
            list<int> neighbors = l[u];
            for (int v : neighbors) {
                indegree[v]++;
            }
        }
    }

    void topoSort() {  //Kahn's Algorithm
        vector<int> indegree(V, 0);
        calIndegree(indegree);
        queue<int> q;
        
        //indegree 0 nodes => starting point 
        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            list<int> neighbors = l[curr];
            for (int v : neighbors) {
                indegree[v]--;
                if (indegree[v] == 0) {  //no pending dependencies
                    q.push(v);
                }
            }
        }
    }
};


int main() {
    Graph graph(6, true);

    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(3, 1);
    graph.addEdge(2, 3);

    graph.topoSort();
    return 0;
}