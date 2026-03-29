#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> m;

    m["India"] = 150;
    m["China"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;

    for (pair<string, int> country : m) {
        cout << country.first << ", " << country.second << endl;
    }

    m.erase("Nepal");

    if (m.count("Nepal")) {
        cout << "Nepal exists\n" ;
    } else {
        cout << "Nepal doesn't exists\n";
    }

    return 0;
}