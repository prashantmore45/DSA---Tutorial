/*
Question 1 : Split a String in Balanced Strings
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
Given a balanced string s, split it into some number of substrings such that: Each substring is balanced.
Return the maximum number of balanced strings you can obtain.

Examples : Input: s = "RLRRLLRLRL" Output: 4

Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains the same number of 'L' and 'R'.
*/

#include<iostream>
using namespace std;

int maxBalancedStringSplit(string s) {
    int n = s.size();
    int ans = 0;
    int countR = 0;
    int countL = 0;

    for (int i=0; i<n; i++) {
        if (s[i] == 'R') {
            countR++;
        } else {
            countL++;
        }

        if (countR == countL) {
            ans++;
            countR = 0;
            countL = 0;
        }
    }

    cout << "maximum number of balanced strings = " << ans << endl;
    return ans;
}

int main() {
    string s = "RLRRLLRLRL";

    maxBalancedStringSplit(s);
    return 0;
}