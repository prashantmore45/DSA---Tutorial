#include<iostream>
using namespace std; 

int factorial(int n){
    if(n==0) return 1; // Base case: factorial of 0 is 1
    return n * factorial(n-1); // Time Complexity: O(n) and Space Complexity: O(n) due to recursive call stack
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<endl;
    return 0;
}