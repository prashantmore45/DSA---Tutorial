#include<iostream>
using namespace std;

void toUppercase(char word[], int n) {
    for (int i = 0; i < n; i++) {
        char ch = word[i];
        if (ch >= 'A' && ch <= 'Z') {
            continue; // Already uppercase
        } else {
            word[i] = ch - ('a' - 'A');
        }
    }
}

int main() {
    char word[] = "ApPle";
    toUppercase(word, 5);
    cout << "Uppercase: " << word << endl;
    return 0;
}