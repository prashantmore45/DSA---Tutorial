/*
for (int i = 0; i < n; i++)
i *= k;

Here, k is some constant value

A. O(n)
B. O(k)
C. O(logkn) (= logn of base k)
D. O(lognk) (= logk of base n)

Answer: C. O(logkn) (= logn of base k)

Explanation:
1. The loop starts with i = 0 and in each iteration, i is multiplied by k. This means that i takes the values 0, k, k^2, k^3, ..., until it exceeds n.
2. The number of iterations can be determined by solving the inequality k^m <= n, where m is the number of iterations. This can be rewritten as m <= logk(n).
3. Therefore, the time complexity of the loop is O(logkn), which is the logarithm of n to the base k.

Dry Run:
Let's take n = 16 and k = 2 as an example:
for (int i = 0; i < 16; i *= 2) {
    // Iteration 1: i = 0 (initial value)
    // Iteration 2: i = 0 * 2 = 0
    // Iteration 3: i = 0 * 2 = 0
    // ...
    // The loop will run indefinitely since i remains 0, which is less than n.
}

In this case, the loop will run indefinitely because i starts at 0 and is multiplied by k (which is 2) in each iteration, resulting in i always being 0. This is a special case where the loop does not terminate as expected. However, if we start with i = 1 instead of 0, the loop would run as follows:

for (int i = 1; i < 16; i *= 2) {
    // Iteration 1: i = 1
    // Iteration 2: i = 1 * 2 = 2
    // Iteration 3: i = 2 * 2 = 4
    // Iteration 4: i = 4 * 2 = 8
    // Iteration 5: i = 8 * 2 = 16 (loop terminates)
}

*/

#include<iostream>
using namespace std;


int main(){
    int n, k;
    cout<<"Enter a number n: ";
    cin>>n;
    cout<<"Enter a constant k: ";
    cin>>k;

    int i = 1;
    while (i < n) {
        cout<<"Current value of i: "<<i<<endl;
        i *= k; // This will cause an infinite loop if i starts at 0
    }

    return 0;
}