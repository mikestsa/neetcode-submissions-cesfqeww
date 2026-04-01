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
    int max_sum = INT_MIN;
public:

    int maxPathSum(TreeNode* root) {
        max_sum = root->val;
        helper(root);
        return max_sum;
    }
     int helper(TreeNode* root) {
        if (!root) return 0;
        int left_sum = max(0, helper(root->left));
        int right_sum = max(0, helper(root->right));
        int sum = root->val + left_sum + right_sum;
        max_sum = max(max_sum, sum);
        return root->val + max(left_sum, right_sum);
    }
    
};
