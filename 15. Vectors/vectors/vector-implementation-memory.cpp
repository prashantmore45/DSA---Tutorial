#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> vec;
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;

    vec.push_back(60);
    cout << "After push_back(60):" << endl; 
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;

    vec.pop_back();
    cout << "After pop_back():" << endl;
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;

    return 0;
}