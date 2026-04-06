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

class Codec {
    int next = -1;
public:

    string serialize(TreeNode* root) {
       string out;
       serialize(root, out);
       return out;
    }
    
    void serialize(TreeNode* root, string& s) {
        if (!root){
            s += 'N';
            s += ',';
            return;
        }
        else{
            s += to_string(root->val);
            s +=',';

        }
        serialize(root->left, s);
        serialize(root->right, s);
       
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        next = 0;
        return deserialize_helper(data);
    }

    TreeNode* deserialize_helper(string& data) {
        if (next >= data.size()) return nullptr;
        size_t next_next = data.find(',', next);
        string current = data.substr(next , next_next - next);
        next = next_next + 1;
        if (current == "N") return nullptr;
        int val = stoi(current);
        TreeNode* current_node = new TreeNode(val);
        current_node->left = deserialize_helper(data);
        current_node->right = deserialize_helper(data);
        return current_node;

        
    }
};
