#include<iostream>
using namespace std;

int sumOfN(int n){
    if(n==0) return 0;
    return n + sumOfN(n-1); // Time Complexity: O(n) and Space Complexity: O(n) due to recursive call stack
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Sum of first "<<n<<" numbers is: "<<sumOfN(n)<<endl;
    return 0;
}