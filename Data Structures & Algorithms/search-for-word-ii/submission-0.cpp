class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word = "";
        int children_count = 0; // ΝΕΟ: Μετρητής παιδιών για O(1) pruning
    };

public:
    vector<string> out;
    int rows, cols; // Αποθηκεύουμε το μέγεθος εδώ για ταχύτητα

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        out.clear();
        rows = board.size();
        cols = board[0].size();
        
        TrieNode* root = new TrieNode();
        for(const auto &word : words){
            TrieNode* node = root; 
            for(int i = 0 ; i < word.size() ; i++){
                int index = word[i] - 'a'; 
                
                if (node->children[index] == nullptr){
                    node->children[index] = new TrieNode();
                    node->children_count++; // Αυξάνουμε τον μετρητή επειδή προσθέσαμε παιδί
                }
                node = node->children[index];
            }
            node->word = word;
        }

        for(int r = 0 ; r < rows; r++){
            for(int c = 0 ; c < cols; c++){
                dfs(board, root, r, c);
            }
        }

        return out;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int r, int c){
        // Αν βρήκαμε λέξη στο προηγούμενο βήμα
        if (root->word != "") {
            out.push_back(root->word);
            root->word = "";
        }
    
        // Χρησιμοποιούμε τις μεταβλητές κλάσης rows και cols
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] == ' ' ) return;

        int char_index = board[r][c] - 'a'; 
        
        if (root->children[char_index] == nullptr) return;

        char current_letter = board[r][c];
        board[r][c] = ' '; // Visited
        
        // --- ΒΕΛΤΙΣΤΟΠΟΙΗΣΗ: Στατικοί πίνακες αντί για vector ---
        static const int dr[] = {-1, 1, 0, 0};
        static const int dc[] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++){
            int current_row = r + dr[i];
            int current_col = c + dc[i];
            dfs(board, root->children[char_index], current_row, current_col);
        }
        
        // Backtracking
        board[r][c] = current_letter;
                
        // --- ΒΕΛΤΙΣΤΟΠΟΙΗΣΗ: O(1) Pruning με τον μετρητή ---
        TrieNode* visitedNode = root->children[char_index];
        
        // Αν δεν έχει άλλα παιδιά ΚΑΙ η λέξη του έχει "αδειάσει" (την έχουμε βρει)
        if (visitedNode->children_count == 0 && visitedNode->word == "") {
            root->children[char_index] = nullptr; 
            root->children_count--; // Μειώνουμε τον μετρητή του γονιού!
            delete visitedNode;
        }
    }
};