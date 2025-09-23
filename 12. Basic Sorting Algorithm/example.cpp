#include <iostream>
using namespace std;

void print(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortchar(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char curr = arr[i];   // Store current character
        int prev = i - 1;

        // Compare character values, not indices
        while (prev >= 0 && arr[prev] > curr) {  
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;  // Place the current character at the correct position
    }

    print(arr, n);
}

int main() {
    char ch[] = {'f', 'b', 'a', 'e', 'c', 'd'};
    int n = sizeof(ch) / sizeof(ch[0]);

    cout << "Before sorting: ";
    print(ch, n);

    cout << "After sorting: ";
    sortchar(ch, n);

    return 0;
}
