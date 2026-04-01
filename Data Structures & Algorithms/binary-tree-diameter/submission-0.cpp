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
int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int out = 0;
        while(q.size()){
            int size = q.size();
            for(int i = 0 ; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                TreeNode* left = node->left;
                TreeNode* right = node->right;
                if (left) q.push(left);
                if (right) q.push(right);

            }
            out++;
        }
        return out;
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int max_left_right = max(left, right);
        return max(max_left_right,  maxDepth(root->left) + maxDepth(root->right));
        
    }
};
