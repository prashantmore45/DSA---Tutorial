#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1 = "Hello World";
    string str2 = "C++ Programming";

    cout << "Length: " << str1.length() << endl;
    cout << str1.at(6) << endl;
    cout << str1.substr(0, 5) << endl;
    cout << str2.find("C++") << endl;
    cout << str2.find("Programming", 0) << endl;
    return 0;
}