/*
Question 4 : Given two binary search trees, return True if and only if there is a node in the first tree and a node in 
the second tree whose values sum up to a given integer target.

Examples :
          5
        /   \
       3     7
      / \   /  \
     2   4 6    8

         10
       /   \
      6     15
     / \    / \
    3   8  11  18

x = 16 (Target)

Output: ans = 3, The pairs are: (5, 11), (6, 10) and (8, 8)
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

//search in BST
bool search(Node* root, int target) {
    if (root == NULL) return false;

    if (root->data == target) return true;

    if (target < root->data)
        return search(root->left, target);
    else
        return search(root->right, target);
}

//main logic
bool isPairPresent(Node* root1, Node* root2, int target) {
    if (root1 == NULL) return false;

    // check current node of BST1
    int remaining = target - root1->data;

    if (search(root2, remaining)) {
        return true;
    }

    // check left and right subtree
    return isPairPresent(root1->left, root2, target) ||
           isPairPresent(root1->right, root2, target);
}

// inorder 
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int arr1[7] = {5, 3, 7, 2, 4, 6, 8}; 
    int arr2[7] = {10, 6, 15, 3, 8, 11, 18};
    int target = 16;

    Node* root1 = buildBST(arr1, 7);
    Node* root2 = buildBST(arr2, 7);

    cout << "BST1: ";
    inorder(root1);
    cout << endl;

    cout << "BST2: ";
    inorder(root2);
    cout << endl;

    if (isPairPresent(root1, root2, target))
        cout << "Pair exists" << endl;
    else
        cout << "No pair found" << endl;

    return 0;
}