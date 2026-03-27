#include<iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> vec;
public:
    
    void push(int val) { //O(logn)
        //step 1: insert val
        vec.push_back(val);

        //fix heap
        int x = vec.size()-1; //child Idx
        int parI = (x-1)/2; //parent Idx

        while (parI>=0 && vec[x] > vec[parI]) { 
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void heapify(int i) {
        if (i >= vec.size()) {
            return;
        }

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int maxIdx = i;

        if (l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;  
        }

        if (r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }

        swap(vec[i], vec[maxIdx]);

        if (maxIdx != i) {  //swaping with child node
            heapify(maxIdx);
        }
    }

    void pop() {
        //step1: swap top element with last element
        swap(vec[0], vec[vec.size()-1]);

        //step2: remove last element
        vec.pop_back();

        //step3: fix heap
        heapify(0);
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }
};

int main() {
    Heap heap;
    heap.push(8);
    heap.push(4);
    heap.push(5);
    heap.push(1);
    heap.push(2);
    heap.push(9);

    // cout << "top = " << heap.top() << endl; //9
    // heap.pop();
    // cout << "top = " << heap.top() << endl; //8

    while (!heap.empty()) {
        cout << "top = " << heap.top() << endl;
        heap.pop();
    }

    return 0;
}