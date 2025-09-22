#include<iostream>
using namespace std;

void trap(int *heights, int n){
    int Leftmax[20000], RighTmax[20000];

    Leftmax[0] = heights[0];
    RighTmax[n-1] = heights[n-1];
    
    for (int i = 0; i < n; i++)
    {
        Leftmax[i] = max(Leftmax[i-1], heights[i-1]);
    }
    for (int i = 0; i < n; i++)
    {
        RighTmax[i] = max(RighTmax[i+1], heights[i+1]);
    }
    int watertrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int currWater = min(Leftmax[i], RighTmax[i]) - heights[i];

        if (currWater > 0){
            watertrapped += currWater;
        }
    }
    cout << "Water Trapped = " << watertrapped << endl;
    
}
int main(){

    int heights[] = { 4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights) / sizeof(int);
    trap(heights, n);
    return 0;
}