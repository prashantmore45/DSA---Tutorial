#include <iostream>
#include <algorithm>  // Include this header for sort()
using namespace std;

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 2, 4, 5, 6, 1};
    
    // Sort the array using std::sort
    sort(arr, arr + 6);
    
    print(arr, 6);
    
    return 0;
}
