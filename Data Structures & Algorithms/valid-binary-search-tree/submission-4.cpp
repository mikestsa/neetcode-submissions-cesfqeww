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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
 
    bool isValidBST(TreeNode* root, int min, int max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        bool is_left_valid = isValidBST(root->left, min, std::min(max, root->val));
        bool is_right_valid = isValidBST(root->right, std::max(min, root->val), max);
        return is_left_valid && is_right_valid;

    }
};
