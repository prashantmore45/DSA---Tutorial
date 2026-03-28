#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }
};

class HashTable {
    int totalSize;
    int currSize;
    Node** table;

    int HashFunction(string key) {
        int idx = 0;

        for (int i=0; i<key.size(); i++) {
            idx = idx + (key[i]*key[i]) % key.size();
        }

        return idx;
    }

public:
    HashTable(int size = 5) {
        this->totalSize = size;

        table = new Node*[totalSize];

        for (int i=0; i<totalSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, val) {
        int idx = HashFunction(key);

        Node* newNode = new Node(key, val);
        Node* head = table[idx];

        newNode->next = head;
        head = newNode;

        currSize++;
    }
};


int main() {
    HashTable ht;
    return 0;
}