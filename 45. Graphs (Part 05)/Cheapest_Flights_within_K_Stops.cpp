#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Info {
public:
    int u;
    int cost;
    int stops;

    Info(int u, int cost, int stops) {
        this->u = u;
        this->cost = cost;
        this->stops = stops;
    }
};

int findCheapestPrice(vector<vector<int>> &flights, int src, int dest, int k) {
    int V = flights.size();
    queue<Info> q;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    q.push(src, 0, -1);

    while (q.size() > 0) {
        Info curr = q.front();
        q.pop();

        for (int i=0; i<V; i++) {
            if (flights[i][0] == curr.u) {
                int v = flights[i][1];
                int wt = flights[i][2];

                if (dist[v] > curr.cost + wt && curr.stops+1 <= k) {
                    dist[v] = curr.cost + wt;
                    q.push(v, dist[v], curr.stops+1);
                }
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        return -1;
    }

    return dist[dest];
}