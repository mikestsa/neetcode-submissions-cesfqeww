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
int total = 0;
    int goodNodes(TreeNode* root) {
         goodNodes(root, INT_MIN);    
         return total;    
    }

    void goodNodes(TreeNode* root, int parent_max) {
        if (!root) return;
        if (root->val >= parent_max) {
            total++;
        }
        goodNodes(root->left, max(parent_max, root->val));
        goodNodes(root->right, max(parent_max, root->val));

        
    }
};
