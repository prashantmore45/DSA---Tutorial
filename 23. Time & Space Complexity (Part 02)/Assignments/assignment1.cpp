/*
Question : Find the Time Complexity of the following:
int i, j, k = 0;

for (i = n / 2; i <= n; i++) {
    for (j = 2; j <= n; j = j * 2) {
        k = k + n / 2;
    }
}

A. O(n)
B. O(N log N)
C. O(n^2)
D. O(n^2Logn)

Answer: B. O(N log N)

Explanation:
1. The outer loop runs from i = n/2 to n, which means it runs approximately n/2 times. This contributes O(n) to the time complexity.
2. The inner loop runs from j = 2 to n, doubling j each time (j = j * 2). This means it runs log2(n) times, contributing O(log n) to the time complexity.
3. Since the inner loop is nested inside the outer loop, we multiply their complexities: O(n) * O(log n) = O(n log n).
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int i, j, k = 0;

    for (i = n / 2; i <= n; i++) {
        for (j = 2; j <= n; j = j * 2) {
            k = k + n / 2;
        }
    }

    cout<<"Value of k: "<<k<<endl;
    return 0;
}