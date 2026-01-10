#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1 = "Hello";
    cout << "Initial string: " << str1 << endl;

    string str2;
    getline(cin, str2);
    cout << "You entered (Second string): " << str2 << endl;

    return 0;
}