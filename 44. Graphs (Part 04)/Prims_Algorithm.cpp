#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> * l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back(make_pair(v, wt));
        l[v].push_back(make_pair(u, wt));
    }

    void primsAlgo(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        //(wt, u) => minHeap
        vector<bool> mst(V, false);

        pq.push(make_pair(0, src));
        int ans = 0; //cost

        while (pq.size() > 0) {
            int u = pq.top().second; //vertex
            int wt = pq.top().first; //weight
            pq.pop();

            if (!mst[u]) {
                mst[u] = true;
                ans += wt;

                list<pair<int, int>> neighbors = l[u];
                for (pair<int, int> n : neighbors) {
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v));
                }
            }
        }

        cout << "Final cost of MST = " << ans << endl;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);

    graph.addEdge(1, 0, 10);
    graph.addEdge(1, 3, 40);

    graph.addEdge(2, 0, 15);
    graph.addEdge(2, 3, 50);

    graph.addEdge(3, 0, 30);
    graph.addEdge(3, 1, 40);
    graph.addEdge(3, 2, 50);

    graph.primsAlgo(0);

    return 0;
}