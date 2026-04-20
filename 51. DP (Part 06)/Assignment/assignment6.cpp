/*
Question 6 : Longest Palindromic Subsequence 
Given a string s, find the longest palindromic subsequence's length in s.
*/

#include<iostream>
#include<vector>
using namespace std;

//Recursion

int solveRec(string &s, int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;

    if (s[i] == s[j]) {
        return 2 + solveRec(s, i + 1, j - 1);
    }

    return max(solveRec(s, i + 1, j), solveRec(s, i, j - 1));
}

int longestPalindromeSubseqRec(string s) {
    return solveRec(s, 0, s.size() - 1);
}

//Memoization

int solveMem(string &s, int i, int j, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (i == j) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == s[j]) {
        return dp[i][j] = 2 + solveMem(s, i + 1, j - 1, dp);
    }

    return dp[i][j] = max(
        solveMem(s, i + 1, j, dp),
        solveMem(s, i, j - 1, dp)
    );
}

int longestPalindromeSubseqMem(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveMem(s, 0, n - 1, dp);
}

int main() {
    string s = "bbbab";
    cout << longestPalindromeSubseqRec(s) << endl;

    cout << longestPalindromeSubseqMem(s) << endl;
    return 0;
}