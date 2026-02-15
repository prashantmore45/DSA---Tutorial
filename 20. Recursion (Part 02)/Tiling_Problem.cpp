#include<iostream>
using namespace std;

int TilingProblem(int n) {

    if (n==0 || n==1) {
        return 1;
    }

    //vertical 
    int ans1 = TilingProblem(n-1);

    //horizonatl
    int ans2 = TilingProblem(n-2);

    return ans1 + ans2;

    //return TilingProblem(n-1) + TilingProblem(n-2); //Or
}

int main() {
    int n = 3;
    cout << TilingProblem(n) << endl;
    return 0;
}