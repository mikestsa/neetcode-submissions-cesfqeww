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
int m_k = 0;
int ret = 0;
    int kthSmallest(TreeNode* root, int k) {
        m_k = k ;
        kthSmallest(root);
        return ret;
    }
    
    void kthSmallest(TreeNode* root) {
        if (m_k == 0) return;
        if (root->left) kthSmallest(root->left);
        m_k--;
        if (m_k == 0)  ret = root->val;;
        if (root->right) kthSmallest(root->right);
        
    }
};
