/*
Question 2 : Longest Word in Dictionary (MEDIUM)
Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character 
at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. 
If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word.

Sample Input 1 : words = ["w","wo","wor","worl","world"]
Sample Output 1 : "world"
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Sample Input 2 : words = ["a","banana","app","appl","ap","apply","apple"]
Sample Output 2 : "apple"
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:

    Trie() {
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;

        for (int i=0; i<key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    void longestHelper(Node* root, string &ans, string temp) {
        for (auto child : root->children) {
            if (child.second->endOfWord) {
                temp += child.first;

                if ((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestWordWithEOW() {
        string ans = "";
        longestHelper(root, ans, "");
        return ans;
    }
};

string longestWord(vector<string> words) {
    Trie trie;
    
    for (int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }

    return trie.longestWordWithEOW();
}

int main() {
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    vector<string> words1 = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << longestWord(words) << endl; //world
    cout << longestWord(words1) << endl; //apple
    return 0;
}