/*
Question 3 : Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, 
leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.
push(x) : Add an item x to rear of queue
pop() : Remove an item from front of queue
size() : Returns the number of elements in the queue.
front() : Finds front item.

Example : Input : Queue is [1, 2, 3, 4, 5] & K = 3 ; Output: [3, 2, 1, 4, 5]

Explanation: After reversing the given input from the 3rd position the output will be 3 2 1 4 5
*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseFirstKElements(queue<int> &q, int k) {
    int n = q.size();
    stack<int> s;

    for (int i=0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    int t = q.size() - k;

    for (int i=0; i<t; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int k = 3;
    
    for (int i=1; i<=5; i++) {
        q.push(i);
    }

    reverseFirstkElements(q, k);

    for (int i=1; i<=5; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}