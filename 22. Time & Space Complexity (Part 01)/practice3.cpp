#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 50;
    int K = 5;
 
    for (int i = 0; i < n; i += K) {  // Outer loop runs n/K times 
        for (int j = 0; j <= K; j++) // inner loop runs K times
        {
           cout << arr[i] << " " << arr[j] << endl; // so total time complexity is O((n/K) * K) = O(n)
        }
    }

    return 0;
}