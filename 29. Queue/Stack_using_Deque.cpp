#include<iostream>
#include<deque>
using namespace std;

class Stack {
    deque<int> deq;
public:
    void push(int data) {
        deq.push_front(data);
        //deq.push_back(data);
    }

    void pop() {
        deq.pop_front(); 
        //deq.pop_back(); 
    }

    int top() {
        return deq.front();
        //return deq.back();
    }

    bool empty() {
        return deq.empty();
    }
};

int main() {
    Stack s;
    
    for (int i=1; i<=4; i++) {
        s.push(i);
    }

    for (int i=1; i<=4; i++) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
