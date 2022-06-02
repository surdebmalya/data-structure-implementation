// https://leetcode.com/problems/insert-into-a-binary-search-tree/

// Medium

class Solution {
private:
    TreeNode *newNode(int val) {
        TreeNode *temp = new TreeNode();
        temp->val = val;
        return temp;
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == NULL)
            return newNode(val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};