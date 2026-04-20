/*
Question 6 : Longest Palindromic Subsequence 
Given a string s, find the longest palindromic subsequence's length in s.
*/

#include<iostream>
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


int main() {
    string s = "bbbab";
    cout << longestPalindromeSubseqRec(s) << endl;
    return 0;
}