#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;

    Node() {}
};

class Trie {
    Node* root;

    int countNodes(Node* node) {
        int count = 0;

        for (auto it : node->children) {
            count += countNodes(it.second);
        }

        return count + 1; 
    }

public:
    Trie() {
        root = new Node();
    }

    void insertSuffix(string &str, int start) {
        Node* temp = root;

        for (int i = start; i < str.length(); i++) {
            char ch = str[i];

            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node();
            }

            temp = temp->children[ch];
        }
    }

    int countUniqueSubstrings(string str) {
        for (int i = 0; i < str.length(); i++) {
            insertSuffix(str, i);
        }

        //return countNodes(root) - 1; //exclude empty string ; count : 9
        return countNodes(root);  //include empty string ; count : 10
    }
};

int main() {
    string str = "ababa";

    Trie trie;
    cout << trie.countUniqueSubstrings(str) << endl; //10

    return 0;
}