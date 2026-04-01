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
    int diameter = 0;

public:

    int diameterOfBinaryTree(TreeNode* root) {
        calculateHeight(root);
        return diameter;
    }
    int calculateHeight(TreeNode* node){
        if (!node) return 0;
        int left_height = calculateHeight(node->left);
        int right_height = calculateHeight(node->right);
        int height = 1 + max(left_height, right_height);
        diameter = max(diameter, left_height + right_height);
        return height;
    }
};
