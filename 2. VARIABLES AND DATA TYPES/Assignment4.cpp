/*Write a program to calculate the area of a circle.
Input : r (radius)
Output : PI*r*r (area)*/

#include<iostream>
//#define PI = 3.14
using namespace std;

int main(){

    float r;
    float PI = 3.14;

    cout<<"Enter the Radius: "<<endl;
    cin>>r;

    float area = PI*r*r;
    cout<<"Area of Circle:"<<area<<endl;

    return 0;

}

