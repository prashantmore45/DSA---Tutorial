//Print factorial of a number.

#include<iostream>
using namespace std;

int factorial(int n){

    int fact = 1;

    for(int i=1; i<=n; i++){

        fact = fact * i;
    }

    return fact;
}

int main(){

    cout << factorial(15) << endl;

    return 0;
}