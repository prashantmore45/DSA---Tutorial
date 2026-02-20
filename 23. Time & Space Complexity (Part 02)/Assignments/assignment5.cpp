/*
Q.(e). Find the time & space complexity of the following code:

int a = 0;
for (int i = 0; i < n; ++i) {
    for (int j = n; j > i; --j) {
        a = a + i + j;
    }
}

Answer:
Time Complexity: O(n^2)
Space Complexity: O(1)

Explanation:
1. The outer loop runs from i = 0 to n-1, which means it runs n times.
2. The inner loop runs from j = n down to i+1. In the worst case, when i = 0, the inner loop runs n times. When i = 1, it runs n-1 times, and so on. The total number of iterations for the inner loop across all iterations of the outer loop can be calculated as:
   - For i = 0: j runs from n to 1 (n iterations)
   - For i = 1: j runs from n to 2 (n-1 iterations)
   - For i = 2: j runs from n to 3 (n-2 iterations)
   - ...
   - For i = n-1: j runs from n to n (1 iteration)

   The total number of iterations is approximately n + (n-1) + (n-2) + ... + 1, which is equal to n(n+1)/2. This simplifies to O(n^2).
3. The space complexity is O(1) because the code uses a constant amount of space for the variable a, regardless of the input size n.

Dry Run:
Let's take n = 3 as an example:
1. Initially, a = 0.
2. For i = 0:
   - j runs from 3 down to 1 (3 iterations):
     - j = 3: a = a + 0 + 3 = 0 + 3 = 3
     - j = 2: a = a + 0 + 2 = 3 + 2 = 5
     - j = 1: a = a + 0 + 1 = 5 + 1 = 6
3. For i = 1:
   - j runs from 3 down to 2 (2 iterations):
     - j = 3: a = a + 1 + 3 = 6 + 4 = 10
     - j = 2: a = a + 1 + 2 = 10 + 3 = 13
4. For i = 2:
   - j runs from 3 down to 3 (1 iteration):
     - j = 3: a = a + 2 + 3 = 13 + 5 = 18

The final value of a is therefore, in this example, equal to the sum of all values of i and j in the nested loops, which is equal to n(n+1)(n+2)/6 for n=3, which is equal to (3*4*5)/6=10.

This confirms that the time complexity is O(n^2) and the space complexity is O(1).

*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int a = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n; j > i; --j) {
            a = a + i + j;
        }
    }

    cout<<"Value of a: "<<a<<endl;
    return 0;
}