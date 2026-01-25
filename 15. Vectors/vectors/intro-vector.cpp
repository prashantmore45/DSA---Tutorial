#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> vec1; // Empty vector
    cout << vec1.size() << "\n"; 

    vector<int> vec2 = {1, 2, 3, 4, 5}; // Vector with initial values
    cout << vec2.size() << "\n";

    vector<int> vec3(10 , -1); // Vector of size 10, initialized with -1
    cout << vec3.size() << "\n";

    for (int i = 0; i < vec3.size(); i++) { 
        cout << vec3[i] << " "; 
    }
    cout << endl;

    return 0;
}