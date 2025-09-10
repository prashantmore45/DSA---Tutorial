/*Enter cost of 3 items from the user (using float data type) - a pencil, a
pen and an eraser. You have to output the total cost of the items back to the user as
their bill.
(Add on : You can also try adding 18% GST tax to the items in the bill as an advanced
problem)*/

#include<iostream>
using namespace  std;

int main(){
    float pencil;
    float pen;
    float eraser;

    cout<<"Enter the cost of pencil:"<<pencil<<endl;
    cin>>pencil;

    cout<<"Enter the cost of pen:"<<pen<<endl;
    cin>>pen;

    cout<<"Enter the cost of eraser:"<<pencil<<endl;
    cin>>eraser;

    //Total Cost:

    float total = pencil + pen + eraser;
    cout<<"Total:"<<total<<endl;

    //Total cost including GST: 

    float total_cost = total + ((18*total)/100);
    cout<<"Total Cost : "<<total_cost<<endl;

    return 0;

}