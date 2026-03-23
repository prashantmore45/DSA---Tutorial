/*
Question 2 : Given the root of a binary tree, invert the tree, and return its root.
Examples : Input: Binary Tree , Output: Inverted Tree

           1                       
         /  \
        2    3
      /  \    \
     4    5    6

           1
         /  \
        3    2
      /     / \
     6     5   4
*/

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes) {
    idx++;

    if (nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

Node* invertedTree(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    Node* left = invertedTree(root->left);
    Node* right = invertedTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);
    preorder(root); //Binary tree
    
    cout << "\n";

    invertedTree(root);
    preorder(root); //inverted binary tree
    return 0;
}
