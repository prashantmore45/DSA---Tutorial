/*
Question 2 : Keypad Combinations

Given a string containing digits from 2-9 inclusive, print all possible letter combinations that 
the number could represent. You can print the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 
does not map to any letters.

Sample Input 1 : digits = "23"
Sample Output 1 : "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"

Sample Input 2 : digits = "2"
Sample Output 2 : "a", "b", "c"

Sample Input 3 : digits = ""
Sample Output 3 : ””
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// DFS + Backtracking function
void dfs(int pos, string &ans, const string &digits,
         const vector<vector<char>> &mp) {
    
    // Base case: all digits processed
    if (pos == digits.length()) {
        cout << ans << " ";
        return;
    }

    int digit = digits[pos] - '0';

    // Try all letters for current digit
    for (char ch : mp[digit]) {
        ans.push_back(ch);          // choose
        dfs(pos + 1, ans, digits, mp); // explore
        ans.pop_back();             // backtrack
    }
}

void letterCombinations(const string &digits) {
    if (digits.empty()) {
        cout << "";
        return;
    }

    vector<vector<char>> mp = {
        {}, {}, {'a','b','c'}, {'d','e','f'},
        {'g','h','i'}, {'j','k','l'},
        {'m','n','o'}, {'p','q','r','s'},
        {'t','u','v'}, {'w','x','y','z'}
    };

    string ans = "";
    dfs(0, ans, digits, mp);
}

int main() {
    string digits = "23";
    letterCombinations(digits);
    return 0;
}