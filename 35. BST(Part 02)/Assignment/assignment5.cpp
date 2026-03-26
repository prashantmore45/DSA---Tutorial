/*
Question 5 : Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:
    ● The left subtree of a node contains only nodes with keys less than the node's
    key.
    ● The right subtree of a node contains only nodes with keys greater than the
    node's key.
    ● Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [1, 4, 3, 2, 4, 2, 5, null, null, null, null, null, null, 4, 6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

Example 2:

Input: root = [4, 3, null, 1, 2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

Example 3:

Input: root = [-4, -2, -5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
 
*/

#include<iostream>
#include<climits>
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

class Info {
public:
    bool isBST;
    int minVal;
    int maxVal;
    int sum;

    Info(bool isBST, int minVal, int maxVal, int sum) {
        this->isBST = isBST;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->sum = sum;
    }
};


int maxSum = 0;

Info maxSumBSTHelper(Node* root) {
    if (root == NULL) {
        return Info(true, INT_MAX, INT_MIN, 0);
    }

    Info left = maxSumBSTHelper(root->left);
    Info right = maxSumBSTHelper(root->right);

    // check BST condition
    if (left.isBST && right.isBST &&
        root->data > left.maxVal &&
        root->data < right.minVal) {

        int currSum = left.sum + right.sum + root->data;

        maxSum = max(maxSum, currSum);

        int currMin = min(root->data, left.minVal);
        int currMax = max(root->data, right.maxVal);

        return Info(true, currMin, currMax, currSum);
    }

    // not BST
    return Info(false, 0, 0, 0);
}

int maxSumBST(Node* root) {
    maxSum = 0;
    maxSumBSTHelper(root);
    return maxSum;
}

Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}


int main() {
    int arr[] = {1, 4, 3, 2, 4, 2, 5, -1, -1, -1, -1, -1, -1, 4, 6};
    int n = 15;

    Node* root = buildTree(arr, n);

    cout << "Max Sum BST: " << maxSumBST(root) << endl;

    return 0;
}