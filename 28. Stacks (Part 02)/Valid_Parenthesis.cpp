#include<iostream>
#include<stack>
using namespace std;

bool isValid(string str) {
    stack<int> s;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else {
            if (s.empty()) {
                return false;
            }

            char top = s.top();

            if ((top == '(' && ch == ')') ||
                 top == '[' && ch == ']' ||
                 top == '{' && ch == '}') {
                    s.pop();
            } else {
                return false;
            }
        }
    }

    if (s.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string str1 = "([{}])";  //Valid: true
    string str2 = "([{])";  //Invalid: false

    cout << isValid(str1) << endl;
    cout << isValid(str2) << endl;
    return 0;
}