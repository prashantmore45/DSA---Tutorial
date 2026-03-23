/*
Question 1 : A binary tree is uni-valued if every node in the tree has the same value.
Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

Examples : Input: root Node of tree   1
Output: true                         / \
                                    1   1
                                   /  \   \
                                  1    1   1


Input: root Node of tree        5
                              /   \
                             5      5
                            /
                           1
Output: false
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

bool isUniValuedBT(Node* root) {
    if (root == NULL) {
        return true;
    }

    if (!isUniValuedBT(root->left) || !isUniValuedBT(root->right)) {
        return false;
    }

    if (root->left != NULL) {
        if (root->data != root->left->data) {
            return false;
        }
    }

    if (root->right != NULL) {
        if (root->data != root->right->data) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> nodes = {1, 1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1}; //true: 1
    vector<int> nodes = {5, 5, 1, -1, -1, -1, 1, -1, -1}; //false: 0
    Node* root = buildTree(nodes);

    cout << isUniValuedBT(root) << endl;
    return 0;
}