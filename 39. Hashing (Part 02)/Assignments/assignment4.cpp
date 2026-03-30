/*
Question 4 : Bulls & Cows
You are playing a game with your friend. You write down a secret number and ask your friend to guess what the number is. 
When your friend makes a guess, you provide a hint with the following info:
    ● The number of "bulls", which are digits in the guess that are in the correct position.
    ● The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. 
    Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.

Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. 
Note that both secret and guess may contain duplicate digits. 

Sample Input 1 : secret = "1807", guess = "7810"
Sample Output 1 : "1A3B"
Explanation: Bulls are highlighted with orange and cows are underlined: "1807", "7810"

Sample Input 2 : secret = "1123", guess = "0111"
Sample Output 2 : "1A1B"
Explanation: Bulls are highlighted with orange and cows are underlined: "0111", (“0111” or “0111”)
*/

#include<iostream>
#include<unordered_map>
using namespace std;

string getHint(string secret, string guess) {
    int bulls = 0, cows = 0;

    unordered_map<char, int> freq;

    // Step 1: Count bulls + store non-bull chars from secret
    for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            freq[secret[i]]++;  // store unmatched secret chars
        }
    }

    // Step 2: Count cows using remaining guess chars
    for (int i = 0; i < guess.size(); i++) {
        if (secret[i] != guess[i]) {
            if (freq[guess[i]] > 0) {
                cows++;
                freq[guess[i]]--; 
            }
        }
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main() {
    string secret = "1123";
    string guess  = "0111";

    cout << getHint(secret, guess);

    return 0;
}