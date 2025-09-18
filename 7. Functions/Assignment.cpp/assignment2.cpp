// Write a function to calculate the sum of digits of a number. 

#include<iostream>
using namespace std;


int digSum(int n) { 
    int res = 0; 
     
    while(n > 0) { 
    res += n % 10;      // res = res + n % 10
    n = n/10; 
    } 
    return res;
}
int main(){

    cout << digSum(123) << endl;
    return 0;
}