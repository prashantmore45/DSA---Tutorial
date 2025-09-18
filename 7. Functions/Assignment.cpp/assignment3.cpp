/* Write a function which takes 2 numbers as parameters (a & b) and 
outputs : a^2 + b^2 + 2*ab. */ 


#include<iostream>
using namespace std;

int result(int a, int b){
    cout << (a*a) + (b*b) + 2 * a * b << endl;
    return (a*a) + (b*b) + 2 * a * b;

}
int main(){

    result(4, 5);
    return 0;

}