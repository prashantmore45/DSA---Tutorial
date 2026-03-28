#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void slidingWindowMax(vector<int> arr, int K) {
    priority_queue<pair<int, int>> pq;

    //first window
    for (int i=0; i<K; i++) {
        pq.push(make_pair(arr[i], i));
    }

    cout << "ans : " << pq.top().first << " ";

    for (int i=K; i<arr.size(); i++) {
        while (!pq.empty() && pq.top().second <= (i-K)) {  //outside window
            pq.pop();
        }

        pq.push(make_pair(arr[i], i));
        cout << pq.top().first << " ";
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    //vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int K = 3;

    slidingWindowMax(arr, K);
    return 0;
}