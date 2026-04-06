class Codec {
    int next = 0; // Ξεκινάμε από το 0
public:

    string serialize(TreeNode* root) {
        string out;
        serialize_helper(root, out);
        return out;
    }
    
    void serialize_helper(TreeNode* root, string& s) {
        if (!root) {
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        serialize_helper(root->left, s);
        serialize_helper(root->right, s);
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        next = 0; // Μηδενισμός για κάθε νέα αποκωδικοποίηση
        return deserialize_helper(data);
    }

    TreeNode* deserialize_helper(string& data) {
        if (next >= data.size()) return nullptr;

        size_t next_comma = data.find(',', next);
        if (next_comma == string::npos) return nullptr;

        string current = data.substr(next, next_comma - next);
        
        next = next_comma + 1;

        if (current == "N") return nullptr;

        TreeNode* current_node = new TreeNode(stoi(current));
        current_node->left = deserialize_helper(data);
        current_node->right = deserialize_helper(data);
        
        return current_node;
    }
};