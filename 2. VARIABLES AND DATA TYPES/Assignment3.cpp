/* Build a Simple Interest Calculator.
Input : principal (P), rate (R), time (T)Output :
(P*R*T) / 100 */

#include<iostream>
using namespace std;

int main(){

    float P;
    float R;
    float T;

    cout<<"Enter Principal:"<<endl; 
    cin>>P;

    cout<<"Enter Rate:" <<endl;
    cin>>R;

    cout<<"Enter Time:" <<endl;
    cin>>T;

    float SI = (P*R*T)/100;
    cout<<"Simple Interest:"<<SI<<endl;

    return 0;

}

