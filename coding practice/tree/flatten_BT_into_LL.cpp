// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Medium

class Solution {
private:
    void preorder(TreeNode* root, queue<TreeNode *>&q) {
        if(root==NULL) return;
        q.push(root);
        preorder(root->left, q);
        preorder(root->right, q);
    }
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        queue<TreeNode *>q;
        preorder(root, q);
        TreeNode* curr=root;
        q.pop();
        while(!(q.empty())) {
            curr->left=NULL;
            curr->right=q.front();
            q.pop();
            curr=curr->right;
        }
    }
};