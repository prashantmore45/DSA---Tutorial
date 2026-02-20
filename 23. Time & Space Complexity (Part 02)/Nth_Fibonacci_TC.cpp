#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0) return 0; // Base case: Fibonacci of 0 is 0
    if(n==1) return 1; // Base case: Fibonacci of 1 is 1
    return fibonacci(n-1) + fibonacci(n-2); // Time Complexity: O(2^n) and Space Complexity: O(n) due to recursive call stack
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Fibonacci of "<<n<<" is: "<<fibonacci(n)<<endl;
    return 0;
}