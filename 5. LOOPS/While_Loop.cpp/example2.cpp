//Print the sum of odd digits of a number:

#include<iostream>
using namespace std;

int main(){
    int n = 10829;
    int digSum = 0;
    while(n>0){
        int lastDig = n % 10;
        if(lastDig = n % 2 != 0){
            digSum += lastDig;

        }
        n = n/10;

    }
    cout<<"Sum = "<<digSum<<endl;
    
    return 0;
}