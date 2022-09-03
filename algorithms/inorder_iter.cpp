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
    // Inorder: 4 2 5 1 3

    stack<struct Node *> st;
    struct Node *node = root;

    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty() == true)
                break;
            node = st.top();
            st.pop();
            cout << node->value << " ";
            node = node->right;
        }
    }

    return 0;
}