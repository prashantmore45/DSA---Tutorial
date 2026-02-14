// Recursion is a programming technique in which a function calls itself in order to solve a problem. It typically involves a base case that stops the recursion and a recursive case that breaks the problem into smaller subproblems.

#include<iostream>
using namespace std;

//recursive function to calculate factorial of a number
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1); // n! = n * (n-1)!  and 0! = 1
}

int main(){
    int ans = factorial(5);
    cout<<ans<<endl;
    return 0;
}