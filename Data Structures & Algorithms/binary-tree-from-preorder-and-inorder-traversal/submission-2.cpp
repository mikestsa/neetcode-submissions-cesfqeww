/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    // Map για γρήγορη εύρεση της θέσης ενός στοιχείου στο inorder vector
    unordered_map<int, int> inorder_map;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Γεμίζουμε το map: τιμή -> index
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        // Καλούμε τη βοηθητική συνάρτηση με τα αρχικά όρια
        return solve(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd) {
        // Base case: αν τα όρια ξεπεραστούν, το υποδέντρο είναι κενό
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // 1. Η ρίζα είναι πάντα το πρώτο στοιχείο του τρέχοντος τμήματος στο preorder
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // 2. Βρίσκουμε τη θέση της ρίζας στο inorder
        int inRootIdx = inorder_map[rootVal];

        // 3. Υπολογίζουμε πόσα στοιχεία υπάρχουν στο αριστερό υποδέντρο
        // Αυτό είναι το "κλειδί" για να χωρίσουμε σωστά το preorder vector
        int leftSize = inRootIdx - inStart;

        // 4. Αναδρομική κατασκευή υποδέντρων
        
        // Αριστερό Υποδέντρο:
        // Στο preorder: ξεκινάμε μετά τη ρίζα (preStart + 1) και παίρνουμε leftSize στοιχεία
        // Στο inorder: από την αρχή έως ένα πριν τη ρίζα
        root->left = solve(preorder, preStart + 1, preStart + leftSize, inStart, inRootIdx - 1);

        // Δεξί Υποδέντρο:
        // Στο preorder: ξεκινάμε μετά το τέλος του αριστερού τμήματος
        // Στο inorder: από ένα μετά τη ρίζα έως το τέλος
        root->right = solve(preorder, preStart + leftSize + 1, preEnd, inRootIdx + 1, inEnd);

        return root;
    }
};