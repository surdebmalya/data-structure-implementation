// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Easy

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode *makeNode(int data) {
        TreeNode *temp = new TreeNode(data);
        return temp;
    }

    TreeNode *makeBST(vector<int> &nums, int start, int end) {
        if (start > end)
            return NULL;
        int mid = (end + start) / 2;
        TreeNode *temp = makeNode(nums[mid]);
        temp->left = makeBST(nums, start, mid - 1);
        temp->right = makeBST(nums, mid + 1, end);
        return temp;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int mid = (end + start) / 2;
        TreeNode *root = makeNode(nums[mid]);
        root->left = makeBST(nums, start, mid - 1);
        root->right = makeBST(nums, mid + 1, end);
        return root;
    }
};