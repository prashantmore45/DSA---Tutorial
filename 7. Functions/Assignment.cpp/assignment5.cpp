/*Write a function that accepts a character (ch) as parameters & returns 
the character that occurs after ch in the English alphabet. 
Eg : input = ‘c’, return value = ‘d’ */


#include<iostream>
using namespace std;

// char getNextCharcter(char ch){
//     ch+=1;
//     return ch;  
    
// }
// int main(){
    
//     cout << getNextCharcter('A') << endl;
   
//     return 0;
// }


char getNextCharacter(char ch) {
    if (ch == 'z') return 'a'; // Wrap around for lowercase
    if (ch == 'Z') return 'A'; // Wrap around for uppercase
    return ch + 1;  
}

int main() {
    cout << getNextCharacter('A') << endl; // Output: B
    cout << getNextCharacter('c') << endl; // Output: d
    cout << getNextCharacter('Z') << endl; // Output: A
    cout << getNextCharacter('z') << endl; // Output: a
    return 0;
}
