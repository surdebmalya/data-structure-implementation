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
public:
    vector<int> result;

    int finding_freq(TreeNode* root, int value) {
        if(root==NULL) return 0;
        if(root->val==value) {
            return 1 + finding_freq(root->left, value) + finding_freq(root->right, value);
        }
        else {
            return finding_freq(root->left, value) + finding_freq(root->right, value);
        }
    }
    void all_nodes_freq(TreeNode* root, int* max_freq) {
        if(root==NULL) return;
        int curr_freq = 1 + finding_freq(root->left, root->val) + finding_freq(root->right, root->val);
        *max_freq = max(*max_freq, curr_freq);
        all_nodes_freq(root->left, max_freq);
        all_nodes_freq(root->right, max_freq);
    }

    void getting_result(TreeNode* root, int max_freq) {
        if(root==NULL) return;
        int curr_freq = 1 + finding_freq(root->left, root->val) + finding_freq(root->right, root->val);
        if(curr_freq==max_freq) result.push_back(root->val);
        getting_result(root->left, max_freq);
        getting_result(root->right, max_freq);
    }

    vector<int> findMode(TreeNode* root) {
        // finding the maximum frequency
        int max_freq=0;
        all_nodes_freq(root, &max_freq);

        // checking case
        getting_result(root, max_freq);

        return result;
    }
};