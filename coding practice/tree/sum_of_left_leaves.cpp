// https://leetcode.com/problems/sum-of-left-leaves/

// Easy

class Solution {
private:
    int sum(TreeNode *root, string stateOfCurrentNode) {
        if (root == NULL)
            return 0;
        else if (root->left == NULL and root->right == NULL) {
            if (stateOfCurrentNode == "left child")
                return root->val;
            else
                return 0;
        } else
            return sum(root->left, "left child") + sum(root->right, "right child");
    }

public:
    int sumOfLeftLeaves(TreeNode *root) {
        return sum(root, "");
    }
};