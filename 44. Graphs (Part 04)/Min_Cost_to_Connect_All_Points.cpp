#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minCost(int src, vector<vector<int>> points, int V) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //(wt, v) => minHeap
    vector<bool> mst(V, false);    

    pq.push(make_pair(0, src));
    int minCost = 0;

    while (pq.size() > 0) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (!mst[u]) {
            mst[u] = true;
            minCost += cost;

            for (int v=0; v<V; v++) {
                if (u != v && !mst[v]) {
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push(make_pair(wt, v));
                }
            }
        }
    }

    return minCost;
}

int main() {
    vector<vector<int>> points = {{3, 12}, {-3, 5}, {-4, 1}};
    int V = points.size();

    cout << "Min Cost to connect all points = " << minCost(0, points, V) << endl; //18
    return 0;
}