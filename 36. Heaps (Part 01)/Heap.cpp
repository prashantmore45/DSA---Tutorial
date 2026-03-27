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

    void pop() {

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

    cout << "top = " << heap.top() << endl; //9
    return 0;
}