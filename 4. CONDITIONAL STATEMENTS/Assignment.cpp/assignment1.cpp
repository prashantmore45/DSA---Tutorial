/*Write a C++ program to get a number from the user and print whether
it's positive, negative or zero.*/

#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;

    if (num>0){
        cout<<"Number is positive"<<endl;

    }else if (num==0){
        cout<<"Number is Zero"<<endl;

    }else{
        cout<<"Number is negative"<<endl;
        
    }

}