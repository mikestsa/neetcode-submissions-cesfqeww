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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> out;

        std::stack<TreeNode*> stack;
        stack.push(root);

        while(stack.size()){
            auto current = stack.top();
            out.push_back(current->val);
            stack.pop();
            if (current->right) stack.push(current->right);

            if (current->left) stack.push(current->left);

        }
        return out;
        
    }
};