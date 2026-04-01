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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            auto curr = q.front();
            q.pop();
            TreeNode* left = curr->left;
            TreeNode* right = curr->right;
            if (left) q.push(left);
            if (right) q.push(right);

            curr->left = right;
            curr->right = left;
        }

        return root;
        
    }
};
