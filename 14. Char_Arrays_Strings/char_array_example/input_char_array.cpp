#include<iostream>
#include<cstring>
using namespace std;

int main() {

    // Reading a single word (up to whitespace)
    char word[30];
    cin >> word;
    cout << "You entered: " << word << endl;
    cout << "Length of the string: " << strlen(word) << endl;

    cin.ignore(1000, '\n'); // clears entire line

    // Reading a full line including spaces
    char sentence[100];
    cin.getline(sentence, 100);
    cout << "You entered the sentence: " << sentence << endl;
    cout << "Length of the sentence: " << strlen(sentence) << endl;
    return 0;
}