/*
Question 1 : Tribonacci Sequence
The Tribonacci sequence Tn is defined as follows:
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.
*/

#include<iostream>
#include<vector>
using namespace std;

//recursion

int tribonacciRec(int n) {

    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

   return tribonacciRec(n-1) + tribonacciRec(n-2) + tribonacciRec(n-3);
}

//Memoization DP

int tribonacciMem(int n, vector<int> &dp) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    if (dp[n] != -1) {
        return dp[n];
    }

    return tribonacciMem(n-1, dp) + tribonacciMem(n-2, dp) + tribonacciMem(n-3, dp);
} 

//Tabulation DP

int tribonacciTab(int n) {
    vector<int> dp(n+1, 0);

    dp[0] = 0;
    dp[1] = dp[2] = 1;

    for (int i = 3; i < n+1; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main() {
    int n = 5;

    cout << tribonacciRec(n) << endl; //7
    
    vector<int> dp(n+1, -1);
    cout << tribonacciMem(n, dp) << endl; //7

    cout << tribonacciTab(n) << endl; //7

    return 0;
}