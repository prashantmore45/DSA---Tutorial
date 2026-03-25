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

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (root->data > val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for (int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

Node* BSTfromSortedVec(vector<int> &nodes, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = st + (end - st)/2;
    Node* curr = new Node(nodes[mid]);

    curr->left = BSTfromSortedVec(nodes, st, mid-1);
    curr->right = BSTfromSortedVec(nodes, mid+1, end);

    return curr;
};

void getInorder(Node* root, vector<int> &nodes) {

    if (root == NULL) {
        return;
    }

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

Node* balancedBST(Node* root) {
    //get inorder seq
    vector<int> nodes;
    getInorder(root, nodes);

    return BSTfromSortedVec(nodes, 0, nodes.size()-1);
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main() {
    int arr[7] = {6, 5, 4, 3, 7, 8, 9};
    Node* root = buildBST(arr, 7);

    //Manual Creation of unbalanced BST

    /*Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);*/

    root = balancedBST(root);
    preorder(root);
    return 0;
}