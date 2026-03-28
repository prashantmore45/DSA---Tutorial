#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};


int main() {
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;  //default - maxHeap; "first"
    pq.push(make_pair("Prashant", 200));
    pq.push(make_pair("Ayushi", 1000));
    pq.push(make_pair("Rohit", 800));

    while (!pq.empty()) {
        cout << "top = " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}