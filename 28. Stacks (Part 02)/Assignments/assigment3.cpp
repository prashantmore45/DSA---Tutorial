/*
Question 3 : We have an absolute path for a file(Unix-style), simplify it. Note that absolute path always begins with ‘/’(rootdirectory), a dot in path 
represents current directory and double dot represents parent directory.

Examples :
Input: path = "/home//foo/" Output: "/home/foo"
Explanation: Multiple consecutive slashes are replaced by a single one.

Input: path = "/home/user/Documents/../Pictures" Output: "/home/user/Pictures"
Explanation: A double period ".." refers to the directory up a level.
*/

#include<iostream>
#include<stack>
using namespace std;

string simplyfyPath(string path) {
    stack<string> s;
    string curr = "";

    for (int i=0; i<=path.size(); i++) {
       
        if (i == path.size() || path[i] == '/') {
            if (curr == "" || curr == ".") {
                //ignore
            } 
            else if (curr == "..") {
                if (!s.empty()) {
                    s.pop();
                } 
            }
            else {
                s.push(curr);
            }

            curr = "";
        } 
        else {
            curr += path[i];
        }
    }

    string result = "";

    while (!s.empty()) {
        result = "/" + s.top() + result;
        s.pop();
    }

    return result.empty() ? "/" : result;
}

int main() {
    string str1 = "/home//foo/";
    string str2 = "/home/user/Documents/../Pictures";

    cout << simplyfyPath(str1) << endl;
    cout << simplyfyPath(str2) << endl;

    return 0;
}