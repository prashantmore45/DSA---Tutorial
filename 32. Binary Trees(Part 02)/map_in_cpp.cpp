#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int, string> m;

    m[101] = "rahul";
    m[102] = "neha";
    m[103] = "rahul";

    cout << m[101] << endl; //rahul
    cout << m[102] << endl; //neha
    cout << m[103] << endl; //rahul

    m[101] = "rajat"; //rajat overrides rahul

    cout << m[101] << endl; //rajat

    cout << m.count(101) << endl; //true: 1
    cout << m.count(202) << endl; //false: 0

    for (auto it : m) {
        cout << "key = " << it.first << " , " << "value = " << it.second << endl; // key = ___ , value = "_____"
    }

    return 0;
}