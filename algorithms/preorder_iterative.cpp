// g++ -std=c++17 -o od .\preorder_iterative.cpp
// ./od.exe

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    struct Node * left;
    struct Node * right;
};

struct Node * TreeNode(int val) {
    struct Node * temp = new struct Node();
    temp->value = val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int main() {
    cout << "Hello World" << endl;
    
    // making tree
    struct Node* root = TreeNode(1);
    root->left = TreeNode(2);
    root->right = TreeNode(3);
    root->left->left = TreeNode(4);
    root->left->right = TreeNode(5);
    // 1 2 4 5 3

    stack<struct Node *> st;
    st.push(root);
    while(!(st.empty())) {
        auto upper = st.top();
        st.pop();
        cout << upper->value << " ";
        if(upper->right!=NULL) {
            st.push(upper->right);
        }
        if(upper->left!=NULL) {
            st.push(upper->left);
        }
    }
    cout << endl;

    return 0;
}