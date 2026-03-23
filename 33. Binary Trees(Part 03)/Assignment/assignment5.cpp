/*
Question 5 : A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

Examples :
Input:

    4
   / \
  2   7

Output : 13

Input:

    -10
    /  \
   9    20
       /  \
      15   7

Output : 42
*/

#include<iostream>
#include<vector>
#include<climits>
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

int maxPathHelper(Node* root, int &maxi) {
    if (root == NULL) {
        return 0;
    }

    int lh = max(0, maxPathHelper(root->left, maxi));
    int rh = max(0, maxPathHelper(root->right, maxi));

    maxi = max(maxi, lh + rh + root->data);

    return root->data + max(lh, rh);
}


int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    maxPathHelper(root, maxi);
    return maxi;
}

int main() {
    vector<int> nodes = {4, 2, -1, -1, 7, -1, -1};
    vector<int> nodes = {-10, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};

    idx = -1;  
    Node* root = buildTree(nodes);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    return 0;
}