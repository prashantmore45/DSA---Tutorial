#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> A = {1, 4, 7, 8};
    vector<int> B = {2, 3, 5, 6};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int minAbsDiff = 0;

    for (int i=0; i<A.size(); i++) {
        minAbsDiff += abs(A[i] - B[i]);
    }

    cout << "MIN abs difference = " << minAbsDiff << endl;

    return 0;   
}