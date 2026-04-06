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
unordered_map<int, int> inorder_num_to_index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i < inorder.size() ; i++) inorder_num_to_index[inorder[i]] = i;
        return buildTree(preorder, 0, 0, preorder.size() - 1);

        
    }

    TreeNode* buildTree(vector<int>& preorder, int preorder_index, int in_start, int to_end) {
        if (in_start < 0 || to_end < 0 || in_start >= preorder.size() || to_end >= preorder.size()) return nullptr;
        if (in_start > to_end || preorder_index < 0 || preorder_index > preorder.size()) return nullptr;
        int current_val = preorder[preorder_index];
        TreeNode* current = new TreeNode(current_val);
        int indorder_index_of_current = inorder_num_to_index[current_val];

        int left_size = indorder_index_of_current - in_start;
        current->left = buildTree(preorder, preorder_index + 1, in_start, in_start + left_size - 1);
        current->right = buildTree(preorder, preorder_index + 1 + left_size , indorder_index_of_current + 1, to_end);
        return current;

        
        
    }
};
