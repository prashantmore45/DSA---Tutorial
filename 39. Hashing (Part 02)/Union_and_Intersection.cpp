#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void getUnion(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;

    for (int i=0; i<arr1.size(); i++) {
        s.insert(arr1[i]);
    }

    for (int i=0; i<arr2.size(); i++) {
        s.insert(arr2[i]);
    }

    cout << "Union = ";

    for (int el : s) {
        cout  << el << " ";
    }
    cout << endl;
}

void getIntersection(vector<int> arr1, vector<int> arr2) {
    unordered_set<int> s;

    for (int i=0; i<arr1.size(); i++) {
        s.insert(arr1[i]);
    }

    cout << "Intersection = ";

    for (int i=0; i<arr2.size(); i++) {
        if (s.find(arr2[i]) != s.end()) {  //FOUND
            cout << arr2[i] << " ";
            s.erase(arr2[i]);
        }
    }
    cout << endl;
}

void printArray(vector<int> arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
} 

int main() {
    vector<int> arr1 = {7, 3, 9};
    vector<int> arr2 = {6, 3, 9, 2, 9, 4};

    cout << "Array 2 : ";
    printArray(arr1);

    cout << "Array 1 : ";
    printArray(arr2);

    getUnion(arr1, arr2);
    getIntersection(arr1, arr2);
    return 0;
}