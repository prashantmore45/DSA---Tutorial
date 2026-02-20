#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    for (int i = 0; i < n; i++) {  // This loop iterates through each element of the array, resulting in a linear time complexity O(n) since it depends on the size of the array.
        for (int j = 0; j < n; j++) {  // This nested loop also iterates through each element of the array, resulting in another linear time complexity O(n).
            cout << arr[i] << " ";  // The total time complexity of this code is O(n^2) due to the nested loops.
        }
    }
    cout << endl;

    return 0;
}