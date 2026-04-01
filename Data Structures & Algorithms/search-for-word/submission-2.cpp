class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size();
        int C = board[0].size();
        for(int r = 0 ; r < R; r++){
            for(int c = 0 ; c < C ; c++){
                if (exist(board, word, 0, r, c)) return true;
            }
        }
        return false;
        
    }

    bool exist(vector<vector<char>>& board, string word, int word_index,int curr_row, int curr_col) {
        if (curr_row < 0 || curr_col < 0 || curr_row >= board.size() || curr_col >= board[0].size()) return false;
        if (board[curr_row][curr_col] != word[word_index]) return false;
        if (word_index == word.size() - 1) return true;

        int c = board[curr_row][curr_col];
        board[curr_row][curr_col] = ' ';

        vector<pair<int, int>> directions = {{0,1}, {0, -1}, {1,0}, {-1, 0}};
        for(auto dir : directions){
            if (exist(board, word, word_index + 1, curr_row + dir.first, curr_col + dir.second)) return true;
        }
        board[curr_row][curr_col] = c;
        return false;

    }
};
