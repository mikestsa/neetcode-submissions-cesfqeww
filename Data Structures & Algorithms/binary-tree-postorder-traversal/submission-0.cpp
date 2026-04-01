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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> out;

        std::stack<TreeNode*> s;
        std::stack<bool> visit;
        s.push(root);
        visit.push(false);

        while(s.size()){
            auto current = s.top();
            s.pop();
            bool has_traversed = visit.top();
            visit.pop();
            if (!has_traversed){
                s.push(current);
                visit.push(true);
                if (current->right) {
                    s.push(current->right);
                    visit.push(false);
                }
                if (current->left) {
                    s.push(current->left);
                visit.push(false);

                }
                

            }
            else{
                out.push_back(current->val);
            }



        }
        return out;
        
        
    }
};