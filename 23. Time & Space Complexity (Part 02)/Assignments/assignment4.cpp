/*
Q.(d). Find the time & space complexity of floorSqrt function in the following code to calculate
square root of a number :

int floorSqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int i = 1, result = 1;

    while (result <= x) {
        i++;
        result = i * i;
    }
    return i - 1;
}

int main() {
    int x = 11;
    cout << floorSqrt(x);
    return 0;
}

Answer:
Time Complexity: O(√x)
Space Complexity: O(1)

Explanation:
1. The function starts by checking if x is 0 or 1, which takes O(1) time.
2. The while loop continues until result exceeds x. In the worst case, when x is a perfect square, the loop will run until i is equal to √x. Therefore, the number of iterations is proportional to √x, leading to a time complexity of O(√x).
3. The space complexity is O(1) because the function uses a constant amount of space for the variables i and result, regardless of the input size x.

Dry Run:
Let's take x = 11 as an example:
1. Initially, i = 1 and result = 1 (since 1*1 = 1).
2. The loop checks if result (1) is less than or equal to x (11). It is, so i is incremented to 2 and result becomes 4 (2*2).
3. The loop checks if result (4) is less than or equal to x (11). It is, so i is incremented to 3 and result becomes 9 (3*3).
4. The loop checks if result (9) is less than or equal to x (11). It is, so i is incremented to 4 and result becomes 16 (4*4).
5. The loop checks if result (16) is less than or equal to x (11). It is not, so the loop terminates and the function returns i - 1, which is 3. Therefore, the floor of the square root of 11 is 3.

*/

#include<iostream>
using namespace std;

int floorSqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int i = 1, result = 1;

    while (result <= x) {
        i++;
        result = i * i;
    }
    return i - 1;
}

int main() {
    int x = 11;
    cout << floorSqrt(x);
    return 0;
}