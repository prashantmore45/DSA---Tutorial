/*
Question 4 : Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

#include<iostream>
#include<vector>
using namespace std;

//recursion

vector<string> generateRec(int n) {

    if (n == 0) return {""};

    vector<string> result;

    for (int i = 0; i < n; i++) {

        vector<string> left = generateRec(i);
        vector<string> right = generateRec(n - 1 - i);

        for (string l : left) {
            for (string r : right) {
                result.push_back("(" + l + ")" + r);
            }
        }
    }

    return result;
}

//memoization

vector<string> generateMemo(int n, vector<vector<string>>& dp) {

    if (n == 0) return {""};

    if (!dp[n].empty()) return dp[n];

    vector<string> result;

    for (int i = 0; i < n; i++) {

        vector<string> left = generateMemo(i, dp);
        vector<string> right = generateMemo(n - 1 - i, dp);

        for (string l : left) {
            for (string r : right) {
                result.push_back("(" + l + ")" + r);
            }
        }
    }

    return dp[n] = result;
}

//tabulation

vector<string> generateTab(int n) {

    vector<vector<string>> dp(n + 1);

    dp[0] = {""};

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {

            for (string left : dp[j]) {
                for (string right : dp[i - j - 1]) {

                    dp[i].push_back("(" + left + ")" + right);
                }
            }
        }
    }

    return dp[n];
}


int main() {

    int n = 3;

    // Recursion
    vector<string> res1 = generateRec(n);
    cout << "Recursion:\n";
    for (auto s : res1) cout << s << " ";

    // Memoization
    vector<vector<string>> dp(n + 1);
    vector<string> res2 = generateMemo(n, dp);

    cout << "\n\nMemoization:\n";
    for (auto s : res2) cout << s << " ";

    // Tabulation
    vector<string> res3 = generateTab(n);

    cout << "\n\nTabulation:\n";
    for (auto s : res3) cout << s << " ";

    return 0;
}