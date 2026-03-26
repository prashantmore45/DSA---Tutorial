/*
Question 3 : Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all 
the values of the nodes in the tree.

Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
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
        if (arr[i] != -1) { //-1: NULL
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        } 
        i++;

        //right child
        if (i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

//method 1

// void inorder(Node* root, int k, int &count, int &ans) {
//     if (root == NULL || count >= k) {
//          return;
//     }

//     inorder(root->left, k, count, ans);

//     count++;
//     if (count == k) {
//         ans = root->data;
//         return;
//     }

//     inorder(root->right, k, count, ans);
// }

// int kthSmallest(Node* root, int k) {
//     int count = 0;
//     int ans = -1;

//     inorder(root, k, count, ans);

//     return ans;
// }


//method2

int search(Node* root, int& K) { 
    if (root == NULL) {
        return -1;
    }

    int leftVal = search(root->left, K); 
    
    if(leftVal != -1) {
        return leftVal;
    }

    K--;

    if(K == 0) {
        return root->data;
    }

    return search(root->right, K);
}

int kthSmallest(Node* root, int k) { 
    return search(root, k);
}


int main() {
    int arr[5] = {3, 1, 4, -1, 2}; //-1: NULL
    //int arr[8] = {5, 3, 6, 2, 4, -1, -1, 1};
    int k = 1;

    Node* root = buildBST(arr, 5);

    //cout << kthSmallest(root, k) << endl; //1

    cout << kthSmallest(root, k) << endl; //1
    return 0;
}


