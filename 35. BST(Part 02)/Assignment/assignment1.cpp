/*
Question 1 : Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a 
value in the inclusive range [low, high]
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
*/

#include<iostream>
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

Node* buildBST(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        //left child
        if (arr[i] != -1) {  //-1 : NULL
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        //right child
        if (i < n && arr[i] != -1) {  //-1 : NULL
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int rangeSumBST(Node* root, int low, int high) {
    if (root == NULL) {
        return 0;
    }

    //if node is smaller than low -> go right
    if (root->data < low) {
        return rangeSumBST(root->right, low, high);
    }

    //if node is greater than high -> go left
    if (root->data > high) {
        return rangeSumBST(root->right, low, high);
    }

    //node is in range
    return root->data + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
    int arr[7] = {10, 5, 15, 3, 7, -1, 18};
    Node* root = buildBST(arr, 7);
    int low = 7, high = 15;
    
    cout << "Sum : " << rangeSumBST(root, low, high) << endl;
    return 0;
}