class Solution {
    vector<vector<string>> out;
    unordered_set<int> positive_diag;
    unordered_set<int> negative_diag;
    unordered_set<int> columns;
public:

    vector<vector<string>> solveNQueens(int n) {
        out.clear();
        std::vector<std::string> puzzle(n, std::string(n, '.'));
        solveNQueens(0, puzzle);
        
        return out;
        
    }

    void solveNQueens(int row, std::vector<std::string>& puzzle) {
        if (row == puzzle.size()) out.push_back(puzzle);
        for(int col = 0; col < puzzle.size(); col++){
            int negative_diag_indx = row - col;
            int positive_diag_indx = row + col;
            if(positive_diag.count(positive_diag_indx) == 0 && 
            negative_diag.count(negative_diag_indx) == 0 &&
            columns.count(col) == 0){
                puzzle[row][col] = 'Q';
                positive_diag.insert(positive_diag_indx);
                negative_diag.insert(negative_diag_indx);
                columns.insert(col);
                solveNQueens(row + 1, puzzle);
                puzzle[row][col] = '.';
                positive_diag.erase(positive_diag_indx);
                negative_diag.erase(negative_diag_indx);
                columns.erase(col);
            }
            
        }
        
    }
};
