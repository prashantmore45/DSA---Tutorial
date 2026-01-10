#include <iostream>
#include <string>
using namespace std;

void isAnagram() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    // Step 1: Length check
    if (str1.length() != str2.length()) {
        cout << "Not an Anagram" << endl;
        return;
    }

    int count[256] = {0};

    // Step 2: Count characters of first string
    for (char c : str1) {
        count[c]++;
    }

    // Step 3: Subtract characters of second string
    for (char c : str2) {
        count[c]--;
    }

    // Step 4: Check frequency array
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            cout << "Not an Anagram" << endl;
            return;
        }
    }

    cout << "Anagram" << endl;
}

int main() {
    isAnagram();
    return 0;
}
