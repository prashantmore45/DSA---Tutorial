/*
Question 2 : You are given two strings s1 and s2 of equal length. A string swap is an 
operation where you choose two indices in a string (not necessarily different) and 
swap the characters at these indices. 
Return true if it is possible to make both strings equal by performing at most one 
string swap on exactly one of the strings. Otherwise, return false. 
Example : 
Input: s1 = "bank", s2 = "kanb" Output: 
true 
Explanation: For example, swap the first character with the last character of s2 to 
make "bank". 
*/

#include <iostream>
#include <string>
using namespace std;

bool canBeEqual(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;

    int first = -1, second = -1;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (first == -1) {
                first = i;
            } else if (second == -1) {
                second = i;
            } else {
                return false; 
            }
        }
    }

    if (first == -1 && second == -1) {
        return true;
    }

    if (second != -1 && s1[first] == s2[second] && s1[second] == s2[first]) {
        return true;
    }

    return false;
}

int main() {
    string s1 = "bank";
    string s2 = "kanb";

    if (canBeEqual(s1, s2)) {

      cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
