// https://leetcode.com/problems/count-complete-tree-nodes/

// Medium

class Solution {
private:
    int leftHeight(TreeNode *root) {
        if (root == NULL)
            return 0;
        else
            return 1 + leftHeight(root->left);
    }
    int rightHeight(TreeNode *root) {
        if (root == NULL)
            return 0;
        else
            return 1 + rightHeight(root->right);
    }
    int nodes(TreeNode *root) {
        int left = leftHeight(root);
        int right = rightHeight(root);
        if (left == right)
            return pow(2, left) - 1;
        else
            return 1 + nodes(root->left) + nodes(root->right);
    }

public:
    int countNodes(TreeNode *root) {
        if (root == NULL) {
            return 0;
        } else
            return nodes(root);
    }
};