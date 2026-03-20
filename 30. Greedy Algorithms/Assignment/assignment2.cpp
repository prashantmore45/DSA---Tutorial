/*
Question 2 : Largest Odd Number in String
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty 
substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

Examples : Input: num = "52" Output: "5"

Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
*/

#include<iostream>
using namespace std;

string largestOddNumber(string num) {
    for (int i=num.length()-1; i>=0; i--) {
        int digit = num[i] - '0';

        if (digit & 1) {
            return num.substr(0, i+1);
        }
    }

    return "";
}

int main() {
    string num = "52";

    cout << largestOddNumber(num) << endl;
    return 0;
}