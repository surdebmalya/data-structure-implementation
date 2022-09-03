#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *TreeNode(int val) {
    struct Node *temp = new struct Node();
    temp->value = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main() {
    // making tree
    struct Node *root = TreeNode(1);
    root->left = TreeNode(2);
    root->right = TreeNode(3);
    root->left->left = TreeNode(4);
    root->left->right = TreeNode(5);
    // Postorder: 4 5 2 3 1

    stack<struct Node *> st;

    return 0;
}