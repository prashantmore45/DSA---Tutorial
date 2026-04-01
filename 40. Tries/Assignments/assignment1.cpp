/*
Question 1 : Group Anagrams Together (MEDIUM)
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all 
the original letters exactly once.

Sample Input 1 : strs = ["eat","tea","tan","ate","nat","bat"]
Sample Output 1 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]

Sample Input 2 : strs = [""]
Sample Output 2 : [[""]]

Sample Input 3 : strs = ["a"]
Sample Output 3 : [["a"]]
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    vector<string> group; // store anagrams 
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        string key = word;
        sort(key.begin(), key.end()); // sort first

        Node* temp = root;

        for (char ch : key) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }

        temp->group.push_back(word); // store original word
    }

    void printGroups(Node* node) {
        if (!node->group.empty()) {
            cout << "[ ";
            for (string w : node->group) {
                cout << w << " ";
            }
            cout << "]\n";
        }

        for (auto &it : node->children) {
            printGroups(it.second);
        }
    }

    void display() {
        printGroups(root);
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    Trie trie;

    for (string word : strs) {
        trie.insert(word);
    }

    trie.display();

    return 0;
}