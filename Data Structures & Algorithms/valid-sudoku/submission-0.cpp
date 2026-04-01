class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, std::unordered_set<char>> row;
        unordered_map<int, std::unordered_set<char>> col;
        unordered_map<int, std::unordered_set<char>> square;
        for(int r = 0; r < 9; r++){
            for(int c = 0 ; c < 9; c++){
                if (board[r][c] == '.') continue;
                int squareIdx = (r / 3) * 3 + (c / 3);
                if(row[r].find(board[r][c]) != row[r].end()) return false;
                if(col[c].find(board[r][c]) != col[c].end()) return false;
                if (square[squareIdx].find(board[r][c]) != square[squareIdx].end()) return false;
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);
                square[squareIdx].insert(board[r][c]);
            }
        }
        return true;
        
    }
};