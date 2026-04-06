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

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dest, int k) {
    queue<Info> q;
    vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

    dist[src][0] = 0;
    q.push(Info(src, 0, -1));

    while (q.size() > 0) {
        Info curr = q.front();
        q.pop();

        for (int i=0; i<flights.size(); i++) {
            if (flights[i][0] == curr.u) {
                int v = flights[i][1];
                int wt = flights[i][2];

                if (curr.stops + 1 <= k + 1 &&
                    dist[v][curr.stops + 1] > curr.cost + wt) {

                    dist[v][curr.stops + 1] = curr.cost + wt;
                    q.push(Info(v, dist[v][curr.stops + 1], curr.stops + 1));
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= k+1; i++) {
        ans = min(ans, dist[dest][i]);
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int n = 3;

    cout << findCheapestPrice(n, flights, 0, 2, 1);
}