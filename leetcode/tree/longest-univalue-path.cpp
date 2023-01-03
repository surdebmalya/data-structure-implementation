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
    int longChain(TreeNode* root, int value) {
        if(root==NULL) return 0;
        else {
            if(root->val==value) {
                return 1 + max(longChain(root->left, value), longChain(root->right, value));
            }
            else {
                return 0;
            }
        }
    }
    void solve(TreeNode* root, int* res) {
        if(root==NULL) return;
        // finding max length in the left side
        int leftLength = 0;
        if(root->left!=NULL) {
            leftLength = longChain(root->left, root->val);
        }
        // finding max length in the right side
        int rightLength = 0;
        if(root->right!=NULL) {
            rightLength = longChain(root->right, root->val);
        }

        int throughIt=0;
        if(leftLength and rightLength) throughIt = leftLength + rightLength;
        *res = max(*res, max(throughIt, max(leftLength, rightLength)));

        solve(root->right, res);
        solve(root->left, res);
    }
    int longestUnivaluePath(TreeNode* root) {
        int res = INT_MIN;
        solve(root, &res);
        if(res==INT_MIN) return 0;
        return res;        
    }
};