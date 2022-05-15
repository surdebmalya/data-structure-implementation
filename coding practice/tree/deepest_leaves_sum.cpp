// https://leetcode.com/problems/deepest-leaves-sum/

// Medium

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
private:
    void findingAllLeaves(TreeNode *root, int currLevel, vector<pair<int, int>> &lvlLeafArr) {
        if (root->left == NULL and root->right == NULL) {
            lvlLeafArr.push_back({currLevel, root->val});
        }
        if (root->left != NULL) {
            findingAllLeaves(root->left, currLevel + 1, lvlLeafArr);
        }
        if (root->right != NULL) {
            findingAllLeaves(root->right, currLevel + 1, lvlLeafArr);
        }
    }

public:
    int deepestLeavesSum(TreeNode *root) {
        if (root->left == NULL and root->right == NULL) {
            return root->val;
        }

        // Assuming the root is at level 0
        vector<pair<int, int>> lvlLeafArr; // pair<level, leafValue>
        findingAllLeaves(root, 0, lvlLeafArr);

        sort(lvlLeafArr.begin(), lvlLeafArr.end(), greater<>());
        int deepestLevel = lvlLeafArr[0].first;
        int result = 0;
        for (int idx = 0; idx < lvlLeafArr.size(); idx++) {
            if (lvlLeafArr[idx].first == deepestLevel) {
                result += lvlLeafArr[idx].second;
            } else
                break;
        }
        return result;
    }
};