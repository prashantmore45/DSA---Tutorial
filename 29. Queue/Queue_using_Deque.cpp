#include<iostream>
#include<deque>
using namespace std;

class Queue {
    deque<int> deque;
public:
    void push(int data) {
        deque.push_back(data);
    }

    void pop() {
        deque.pop_front();
    }

    int front() {
        return deque.front();
    }

    bool emptY() {
        return deque.empty();
    }
};

int main() {
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.emptY()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}