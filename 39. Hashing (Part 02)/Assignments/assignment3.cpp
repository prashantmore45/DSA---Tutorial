/*
Question 3 : Sort by Frequency
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is 
the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them. 

Sample Input 1 : s = "cccaaa"
Sample Output 1 : "aaaccc"
Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Sample Input 2 : s = "tree"
Sample Output 2 :"eert"
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

string sortByFreq(string s) {
    unordered_map<char, int> freq;
    // Count frequency
    for (char ch : s) {
        freq[ch]++;
    }

    // Move to vector
    vector<pair<char, int>> vec(freq.begin(), freq.end());

    // Sort by frequency (descending)
    sort(vec.begin(), vec.end(), [](pair<char,int> a, pair<char,int> b) {
        return a.second > b.second;
    });

    // result
    string result = "";

    for (auto p : vec) {
        result += string(p.second, p.first);
    }

    return result;
}

int main() {
    string s = "cccaaa";
    string s1 = "tree";

    cout << sortByFreq(s) << endl; //aaaccc or cccaaa
    cout << sortByFreq(s1) << endl; //eert
    return 0;
}