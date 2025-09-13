/*Write a C++ program that takes a year from the user and print whether
that year is a leap year or not.*/

#include<iostream>
using namespace std;

int main(){
    int year;
    cout<<"Enter Year:";
    cin>>year;

    if (year%4==0){
        cout<<year<<" is leap year"<<endl;
    }
    else if (year%100==0){
        cout << year <<" is not leap year"<<endl;
    }
    else if (year%100==0){
        cout << year <<" is not leap year"<<endl;
    }
    else{
        cout << year <<" is not leap year"<<endl;
    }
    return 0;
}