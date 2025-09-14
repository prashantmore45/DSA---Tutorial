/* WAP to input a number and check whether the number is an Armstrong 
number or not. */

#include<iostream>
using  namespace std;

int main(){

    int n = 371;
    int num = n;
    int cubeSum = 0;

    while(n>0){
        int lastdig = n % 10;
        cubeSum += lastdig * lastdig * lastdig;
        n = n / 10;
    }

    if (num == cubeSum){

        cout << "Armstrong Number\n";
    
    }else{

        cout << "Not an Armstrong Number\n";
    
    }

    return 0;
    
}