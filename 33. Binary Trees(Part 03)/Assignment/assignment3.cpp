/*
Question 3 : Given a binary tree root and an integer target, delete all the leaf nodes with value target.
Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, 
it should also be deleted (you need to continue doing that until you cannot).
Examples : 
Input: target = 2

           1
         /  \
        2    3
      /     / \
     2     2   4

Output:

    1
     \
      3
       \
        4
*/

#include<iostream>
#include<vector>
#include<queue>
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

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        if (curr == NULL) {
            cout << endl;
            if (Q.empty()) {
                break;
            }
            Q.push(NULL); //to track next line
        } else {
            cout << curr->data << " ";

            if (curr->left != NULL) {
                Q.push(curr->left);
            }

            if (curr->right != NULL) {
                Q.push(curr->right);
            }
        }
    }
}

Node* removeLeafNode(Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    Node* left = removeLeafNode(root->left, target);
    Node* right = removeLeafNode(root->right, target);

    if (left == NULL && right == NULL && root->data == target) {
        return NULL;
    }

    root->left = left;
    root->right = right;

    return root;
}

int main() {
    vector<int> nodes = {1, 2, 2, -1, -1, -1, 3, 2, -1, -1, 4, -1, -1};
    Node* root = buildTree(nodes);
    int target = 2;

    root = removeLeafNode(root, target);
    levelOrderTraversal(root);
    return 0;
}