// https://leetcode.com/problems/path-sum-ii/

// Medium

class Solution {
private:
    vector<vector<int>> result;
    void f(TreeNode *root, int sum, vector<int> &arr, int targetSum) {
        if (root->left == NULL and root->right == NULL) {
            // it's a leaf
            if (sum == targetSum)
                result.push_back(arr);
        } else {
            if (root->left != NULL and root->right != NULL) {
                arr.push_back(root->left->val);
                f(root->left, sum + root->left->val, arr, targetSum);
                arr.pop_back();
                arr.push_back(root->right->val);
                f(root->right, sum + root->right->val, arr, targetSum);
                arr.pop_back();
            } else if (root->left != NULL and root->right == NULL) {
                arr.push_back(root->left->val);
                f(root->left, sum + root->left->val, arr, targetSum);
                arr.pop_back();
            } else if (root->left == NULL and root->right != NULL) {
                arr.push_back(root->right->val);
                f(root->right, sum + root->right->val, arr, targetSum);
                arr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == NULL)
            return result;
        vector<int> arr = {root->val};
        f(root, root->val, arr, targetSum);
        return result;
    }
};