/*
Question 2 : We have a binary search tree and a target node K. The task is to find the node with minimum absolute difference with 
given target value K.
Examples :
     8
    / \
   5   11
  / \    \
3    6    20

Input 1: K = 5 Output 1 : ans = 5 (abs diff = 0)

Input 2 : K = 19 Output 2: ans = 20 (abs diff = 1)
*/

#include<iostream>
#include<queue>
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

Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        // left child
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}


int closestValue(Node* root, int K) {
    int closest = root->data;
    int minDiff = abs(root->data - K);

    while (root != NULL) {
        int currDiff = abs(root->data - K);

        if (currDiff < minDiff) {
            minDiff = currDiff;
            closest = root->data;
        }

        if (K < root->data) {
            root = root->left;
        } else if (K > root->data) {
            root = root->right;
        } else {
            return root->data;
        }
    }

    return closest;
}

int main() {
    // Level order input (-1 = NULL)
    int arr[] = {8, 5, 11, 3, 6, -1, 20};
    int n = 7;

    Node* root = buildTree(arr, n);
    int K = 19;

    int ans = closestValue(root, K);

    cout << "Closest value: " << ans << endl;
    cout << "Minimum difference: " << abs(ans - K) << endl;

    return 0;
}