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
private:
    int diff = 0;

    int calculateHeight(TreeNode* node) {
        if (!node) return 0;

        int left_height = calculateHeight(node->left);
        int right_height = calculateHeight(node->right);

        // Η διάμετρος σε αυτόν τον κόμβο είναι το άθροισμα των υψών των παιδιών του
        diff = max(diff, abs(left_height - right_height));

        // Επιστρέφουμε το ύψος του τρέχοντος κόμβου
        return 1 + max(left_height, right_height);
    }

public:
    int isBalanced(TreeNode* root) {
        diff = 0; 
        calculateHeight(root);
        return diff < 2;
    }
};