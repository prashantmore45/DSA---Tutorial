// WAP to find the Factorial of a number entered by the user.

#include<iostream>
using namespace std;
int main(){
    int n;
    int fact = 1;
    cout << "Enter the Number:";
    cin>>n;

    for(int i=1;i<=n;i++){
         fact = fact * i;
        
    }
    cout << "Factorial of a Number is " << fact <<endl;
    return 0;


}