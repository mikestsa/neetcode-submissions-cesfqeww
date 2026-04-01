class NumMatrix {
    vector<vector<int>> m_sum_till_row_col;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> sum_till_row_col(rows, vector<int>(columns, 0));
        int sum = 0;
        for(int r = 0 ; r < matrix.size() ; r++){
            for(int c = 0 ; c < matrix[0].size(); c++){
                int panw = 0;
                int aristera = 0;
                int vgazw = 0;

                if (r > 0) panw = sum_till_row_col[r-1][c];
                if (c > 0) aristera = sum_till_row_col[r][c-1];
                if (c > 0 && r > 0) vgazw = sum_till_row_col[r - 1][c-1];
                sum_till_row_col[r][c] = matrix[r][c] + panw + aristera - vgazw;
            }
        }
        m_sum_till_row_col = sum_till_row_col;
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int out =  m_sum_till_row_col[row2][col2] ;
        if (row1 > 0 ) out -= m_sum_till_row_col[row1 - 1][col2];
        if (col1 > 0) out -= m_sum_till_row_col[row2][col1 - 1];
        if (col1>0 && row1> 0) out += m_sum_till_row_col[row1 -1][col1 - 1];
        return out;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */