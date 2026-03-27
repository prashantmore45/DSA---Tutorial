#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> pq;  //default priority based on largest (max) value
    //priority_queue<int, vector<int>, greater<int>> pq; // priority based smallest (min) value

    pq.push(9);
    pq.push(10);
    pq.push(7);
    pq.push(6);
    pq.push(5);

    while (!pq.empty()) {
        cout << "top: " << pq.top() << endl;
        pq.pop(); 
    }

    return 0;
}