// https://leetcode.com/problems/binary-tree-tilt/

// Easy

class Solution {
private:
    int helper(TreeNode* root) {
        if(root==NULL) return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        int temp=root->val+left+right;
        root->val = abs(left - right);
        return temp;
    }
    void getTheSum(TreeNode* root, int* sum) {
        if(root==NULL) return;
        *sum += root->val;
        getTheSum(root->left, sum);
        getTheSum(root->right, sum);
    }
public:
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root);
        
        int answer=0;
        getTheSum(root, &answer);
        return answer;
    }
};