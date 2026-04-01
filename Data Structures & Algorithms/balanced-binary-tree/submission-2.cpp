class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // Αν η calculateHeight επιστρέψει -1, σημαίνει ότι βρέθηκε ανισορροπία
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Πρόωρη έξοδος από το αριστερό

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Πρόωρη έξοδος από το δεξί

        // Αν η διαφορά είναι > 1, "χτύπα" σφάλμα (-1)
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Αλλιώς επέστρεψε το ύψος κανονικά
        return 1 + max(leftHeight, rightHeight);
    }
};